/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:21:03 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/08 10:36:19 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	s = s + len;
	if (*s == (char) c)
		return ((char *)s);
	while (len >= 0)
	{
		if (*s == (char) c)
			return ((char *)s);
		s--;
		len--;
	}
	return (0);
}
