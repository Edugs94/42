/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:14:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/30 08:55:55 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *s) // cambiar a strndup ??
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_trim (char **buffer)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*first_half;
	char	*second_half;
	char	*tmp_buf;

	i = 0;
	j = 0;
	while (*buffer[i] && *buffer[i] != '\n')
		i++;
	first_half = malloc (i + 1);
	if (!first_half)
		return (NULL);
	second_half = malloc (ft_strlen(*buffer) - i + 1);
	if (!second_half)
		return (NULL)
	k = i;
	while (*buffer[i] && *buffer[i] == '\n')
		i++;
	return(first_half);
}

char	*ft_read_and_fill(int fd)
{
	ssize_t		bytes;
	char		*buffer;
	char		*tmp_cpy;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	return (buffer);
}

char	*build_line(char *buffer, int fd)
{
	if (ft_strchr(buffer, '\n') != NULL)
		return (ft_trim(&buffer)); //in progress
	if (ft_strchr(buffer, '\n') == NULL)//in progress
		return (ft_trim);//in progress
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || *buffer =='\0')
		buffer = ft_read_and_fill(int fd);
	line = build_line (line, buffer);
	if (!buffer || *buffer =='\0')
		free(buffer);
	return (line);
}
