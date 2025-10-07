/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:51:55 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/07 15:40:52 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[start + i] && i < len)
		i++;
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (0);
	j = 0;
	while (j < i)
	{
		ptr[j] = s[start + j];
		j++;
	}
	return (ptr);
}
