/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:14:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/23 11:14:12 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*build_str(char *str, char *buffer)
{
	char	*tmp_str;

	tmp_str = ft_strjoin(str, buffer);
	if (!tmp_str)
		return (NULL);
	free (str);
	return (tmp_str);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*next_line;
	ssize_t		bytes;

	ft_memset(buffer, '\0', BUFFER_SIZE);
	next_line = malloc(1);
	next_line[0] = '\0';
	bytes = read(fd, buffer, 1);
	if (bytes <= 0)
		return (NULL);
	while (bytes > 0 && buffer[0] != '\n')
	{
		next_line = build_str(next_line, buffer);
		ft_memset(buffer, '\0', BUFFER_SIZE);
		bytes = read(fd, buffer, 1);
	}
	return (next_line);
}
