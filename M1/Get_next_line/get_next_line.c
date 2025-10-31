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

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_trim(char **buffer)
{
	size_t	i;
	char	*line;
	char	*new_buffer;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = ft_substr(*buffer, 0, i);
	if (!line)
		return (NULL);
	if ((*buffer)[i] == '\n')
		i++;
	new_buffer = ft_substr(*buffer, i, ft_strlen(*buffer) - i);
	if (!new_buffer)
	{
		free(line);
		return (NULL);
	}

	free(*buffer);
	*buffer = new_buffer;

	return (line);
}

char	*ft_read_and_fill(int fd)
{
	ssize_t	bytes;
	char	*buffer;

	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
char	*build_line(char **buffer, int fd)
{
	char	*tmp;
	char	*readed;

	while (!ft_strchr(*buffer, '\n'))
	{
		readed = ft_read_and_fill(fd);
		if (!readed)
			break;
		tmp = ft_strjoin(*buffer, readed);
		free(readed);
		free(*buffer);
		*buffer = tmp;
		if (!*buffer)
			return (NULL);
	}
	return (ft_trim(buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_read_and_fill(fd);
	if (!buffer)
		return (NULL);

	line = build_line(&buffer, fd);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!*buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}