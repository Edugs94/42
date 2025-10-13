/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:59:32 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/28 16:59:32 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	len_dst = 0;
	while (len_dst < size && dst[len_dst])
		len_dst++;
	if (len_dst == size)
		return (size + ft_strlen(src));
	i = len_dst;
	j = 0;
	while ((i + j < size - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len_dst + ft_strlen(src));
}
