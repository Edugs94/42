/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 07:12:55 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/08 12:08:51 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

size_t	word_len(char const *s, char c, size_t *index)
{
	size_t	start;
	size_t	end;

	start = *index;
	while (s[start] == c)
		start++;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	*index = end;
	return (end - start);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	*index;
	size_t	tmp;
	size_t	i;
	size_t	len;

	i = 0;
	index = (size_t *)malloc(sizeof(size_t));
	if (index == NULL)
		return (0);
	*index = 0;
	matrix = (char **)malloc(sizeof(char *) * words_count(s, c));
	while (i < words_count(s, c))
	{
		tmp = *index;
		len = word_len(s, c, index);
		matrix[i] = (char *)malloc(sizeof(char) * len + 1);
		if (matrix[i] == NULL)
			return (0);
		ft_strlcpy(matrix[i], s + tmp, len);
		matrix[i][len] = '\0';
		i++;
	}
	return (matrix);
}
