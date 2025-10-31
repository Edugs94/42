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

char	*ft_strdup(const char *s)
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

static char	*read_and_build(char *first_half, char *buffer, int fd)
{
	ssize_t		bytes;
	char		*tmp_cpy;

	if (ft_strchr(first_half, '\n') != NULL)
		return (first_half);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	else
	{
		tmp_cpy = ft_strdup (first_half);
		free(first_half);
		first_half = ft_strjoin(tmp_cpy, buffer);
		free(tmp_cpy);
		if (!first_half)
			return (NULL);
		if (ft_strchr(first_half, '\n') != NULL)
			return (first_half);
		else
			first_half = read_and_build(first_half, buffer, fd);
	}
	return (first_half);
}

int	ft_trim(char *first_half, char **second_half)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (first_half[i] && first_half[i] != '\n')
		i++;
	k = i;
	while (first_half[i] && first_half[i] == '\n')
		i++;
	while (first_half[i + j])
		j++;
	//if (j == 0) //linea problematica
	//	return (-2);
	*second_half = (char *)malloc (sizeof(char) * j + 1);
	if (!(*second_half))
		return (-1);
	j = 0;
	while (first_half[i + j])
	{
		(*second_half)[j] = first_half[i + j];
		j++;
	}
	(*second_half)[j] = '\0';
	first_half[k] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	char		*first_half;
	static char	*second_half;
	char		buffer[BUFFER_SIZE + 1];
	int			error_handle;

	first_half = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (second_half && *second_half != '\0')
	{
		first_half = strdup (second_half);
		free(second_half);
	}
	first_half = read_and_build(first_half, buffer, fd);
	if (!first_half || *first_half == '\0')
	{
		if (*second_half == '\0')
			free(second_half);
		return (NULL);
	}
	error_handle = ft_trim(first_half, &second_half);
	if (error_handle == -1)
		return (NULL);
	return (first_half);
}
