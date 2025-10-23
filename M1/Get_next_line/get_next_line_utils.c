/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:20:20 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/23 11:20:20 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

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

char	*ft_strjoin(char *dst, const char *src)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	len;
	
	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	joined = malloc(len * sizeof(char) + 1);
	if (!joined)
		return (NULL);
	while (dst[i])
	{
		joined[i] = dst[i];
		i++;
	}
	while (src[j])
	{
		joined[i + j] = src[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}