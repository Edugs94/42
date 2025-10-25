/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
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
		3.1 Lo que hay antes del salto de linea almacenarlo en next_line
		3.2 el resto apuntarlo con puntero estático
	4. Si no encuentra salto de linea ni null almacenar en next_line
	5. Si no ha encontrado salto de linea volver a hacer el proceso de arriba
*/

static char	*read_and_build(char *str, char *buffer, int fd)
{
	ssize_t		bytes;
	char		*tmp_cpy;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	else
	{
		tmp_cpy = ft_calloc( 1, ft_strlen(str) + 1);
		strcpy (tmp_cpy, str);
		str = ft_strjoin(tmp_cpy, buffer);
		free(tmp_cpy);
		if (!str)
			return (NULL);
		if (ft_strchr(str,'\n') != NULL)
			return (str);
		else
			str = read_and_build(str, buffer, fd);
	}
	return (str);
}

char	*ft_trim(char *str, char *next_line)
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
	next_line = str;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*current_line;
	char		buffer[BUFFER_SIZE + 1];

	if (!next_line)
	{
		next_line = ft_calloc(1, BUFFER_SIZE * 2 * sizeof(char) + 1);
		if (!next_line)
			return (NULL);
	}
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	current_line = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);
	if (!current_line)
		return (NULL);
	current_line[BUFFER_SIZE] = '\0';
	current_line = read_and_build(next_line, buffer, fd);
	if (ft_strchr(current_line,'\n') != NULL)
	{
		next_line = ft_trim(current_line, next_line);
		if(next_line == NULL)
			return (NULL);
	}
	return (free(next_line), current_line);
}
