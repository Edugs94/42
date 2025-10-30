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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

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

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	else
	{
		tmp_cpy = ft_strdup (first_half);
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

static char	*ft_trim(char *first_half, char *second_half)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (first_half[i] && first_half[i] != '\n')
		i++;
	j = i;
	while (first_half[i] == '\n')
		i++;
	second_half = ft_substr(first_half, i, (ft_strlen(first_half) - i) + 1);
	if (!second_half)
		return (NULL);
	first_half[j] = '\0';
	return (second_half);
}

char	*get_next_line(int fd)
{
	char		*first_half;
	static char	*second_half;
	char		buffer[BUFFER_SIZE + 1];

	first_half = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);//1
	if (!first_half)
		return (NULL);
	if (second_half)
	{
		free(first_half);//1
		first_half = ft_strdup(second_half);//2
		if (!first_half)
			return (NULL);
		if (ft_strchr(first_half, '\n') != NULL)
		{
			second_half = ft_trim(first_half, second_half);
			return (first_half);
		}
	}
	first_half = read_and_build(first_half, buffer, fd);
	if (!first_half)
		return (NULL);
	if (ft_strchr(first_half, '\n') != NULL)
		second_half = ft_trim(first_half, second_half);
	if (!second_half || !*second_half)
		free(second_half);
	return (first_half);
}
