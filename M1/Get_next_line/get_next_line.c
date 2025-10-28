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

static char	*read_and_build(char *first_half, char *second_half, char *buffer, int fd)
{
	ssize_t		bytes;
	char		*tmp_cpy;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	else
	{//replantear todo esto, 
		tmp_cpy = ft_calloc( 1, BUFFER_SIZE + 1);
		if (!first_half && (ft_strchr(second_half,'\n') != NULL) )
			first_half = ft_strjoin(second_half, buffer);
		strcpy (tmp_cpy, second_half);
		first_half = ft_strjoin(tmp_cpy, buffer);
		free(tmp_cpy);
		if (!first_half)
			return (NULL);
		if (ft_strchr(first_half,'\n') != NULL)
			return (first_half);
		else
			first_half = read_and_build(first_half, second_half, buffer, fd);
			//revisar esto, tengo que construir la linea completa si el buffer no abarca sufficiente
	}
	return (first_half);
}

char	*ft_trim(char *first_half, char *second_half)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (first_half[i] != '\n')
			i++;
	first_half[i] = '\0';
	i++;
	while (first_half[i] == '\n')
		i++;
	while (first_half[i + j] != '\0')
	{
		second_half[j] = first_half[i + j];
		j++;
	}
	return (second_half);
}

char	*get_next_line(int fd)
{
	char		*first_half;
	static char	*second_half;
	char		buffer[BUFFER_SIZE + 1];

	if (!second_half)
	{
		second_half = ft_calloc(1, BUFFER_SIZE * sizeof(char)+ 1);
		if (!second_half)
			return (NULL);
	}
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	first_half = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);
	if (!first_half)
		return (NULL);
	first_half = read_and_build(first_half, second_half, buffer, fd);
	if (ft_strchr(first_half,'\n') != NULL)
	{
		second_half = ft_calloc(1, BUFFER_SIZE + 1);
		if(second_half == NULL)
			return (NULL);
		second_half = ft_trim(first_half, second_half);
	}
	return (first_half);
}
