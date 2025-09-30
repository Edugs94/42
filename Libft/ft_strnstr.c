/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:39:33 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/30 18:32:04 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);

	while (big[i] && little[j] && i < len)
	{
		if (big[i] != little[j])
		{
			i++;
		}
		else
			while (big[i] == little[j])
			{
				i++;
				j++;
			}
			return ((char *)(big + (i - j)));
	}
	return (0);
}
