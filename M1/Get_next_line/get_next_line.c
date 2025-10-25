/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_second_half.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:14:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/25 17:35:05 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	1. Leer con buffer_size
	2. Almacenar todo en nueva linea
	2.1 Hacer join de la nueva linea con la vieja linea
	3. Si encuentra salto de linea hacer substr 
		3.1 Lo que hay antes del salto de linea almacenarlo en second_half
		3.2 el resto apuntarlo con puntero estático
	4. Si no encuentra salto de linea ni null almacenar en second_half
	5. Si no ha encontrado salto de linea volver a hacer el proceso de arriba
*/

static char	*read_and_build(char *second_half, char *buffer, int fd)
{
	ssize_t		bytes;
	char		*tmp_cpy;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	else
	{
		tmp_cpy = ft_calloc( 1, ft_strlen(second_half) + 1);
		strcpy (tmp_cpy, second_half);
		free(second_half); // esto hace que pete
		second_half = ft_strjoin(tmp_cpy, buffer);
		free(tmp_cpy);
		if (!second_half)
			return (NULL);
		if (ft_strchr(second_half,'\n') != NULL)
			return (second_half);
		else
			second_half = read_and_build(second_half, buffer, fd);
	}
	return (second_half);
}

char	*ft_trim(char *str, char *second_half)
{
	char	*result;

	result = ft_calloc( 1, ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	while (*str != '\n')
	{
			*result = *str;
			result++;
			str++;
	}
	while (*str == '\n')
		str++;
	second_half = str;
	return (second_half);
}

char	*get_next_line(int fd)
{
	char		*first_half;
	static char	*second_half;
	char		buffer[BUFFER_SIZE];

	if (!second_half)
	{
		second_half = ft_calloc(1, BUFFER_SIZE * 2 * sizeof(char) + 1);
		if (!second_half)
			return (NULL);
	}
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	first_half = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);
	if (!first_half)
		return (NULL);
	first_half[BUFFER_SIZE] = '\0';
	first_half = read_and_build(second_half, buffer, fd);
	if (ft_strchr(first_half,'\n') != NULL)
	{
		second_half = ft_calloc(1, BUFFER_SIZE + 1);
		if(second_half == NULL)
			return (NULL);
		second_half = ft_trim(first_half, second_half);
		if(second_half == NULL)
			return (NULL);
	}
	return (first_half);
}
