/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:14:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/24 18:12:43 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*build_str(char *str, char *buffer)
{
	str = ft_strjoin(str, buffer);
	if (!str)
		return (NULL);
	return (str);
}

int	read_chunk(char *next_line, char *buffer, ssize_t bytes, int fd)
{
	static unsigned int	i = 1;

	while (bytes > 0)
	{
		if (ft_strchr(buffer, '\n') == NULL)
		{
			next_line = build_str(next_line, buffer);
			if (!next_line)
				return (-1);
			ft_memset(buffer, '\0', BUFFER_SIZE);
			bytes = read(fd, buffer, (BUFFER_SIZE - 1)/ i);
		}
		else
		{
			i = 2 * i;
			read_chunk(next_line, buffer, bytes, fd);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buffer;
	ssize_t		bytes;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_memset(buffer, '\0', BUFFER_SIZE);
	next_line = malloc(1);
	if (!next_line)
		return (NULL);
	next_line[0] = '\0';
	bytes = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes <= 0)
		return (NULL);
	if (read_chunk(next_line, buffer, bytes, fd) < 0)
		return (NULL);
	free(buffer);
	return (next_line);
}
