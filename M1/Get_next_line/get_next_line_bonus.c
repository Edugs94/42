/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:32:15 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/01 17:28:30 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if ((*buffer)[i] && (*buffer)[i] == '\n')
		i++;
	line = ft_substr(*buffer, 0, i);
	if (!line)
		return (NULL);
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
	ssize_t	bytes;

	while (!ft_strchr(*buffer, '\n'))
	{
		readed = ft_calloc(1, BUFFER_SIZE + 1);
		if (!readed)
			return (NULL);
		bytes = read(fd, readed, BUFFER_SIZE);
		if (bytes < 0)
			return (free(readed), NULL);
		if (bytes == 0)
		{
			free(readed);
			break ;
		}
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
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_read_and_fill(fd);
	if (!buffer[fd])
		return (NULL);
	line = build_line(&buffer[fd], fd);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!(*buffer[fd]))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
