/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:59:20 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/29 17:59:20 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if(*s == (char) c)
			return ((char *)s);
		s++;
	}
	if(*s == (char) c)
			return ((char *)s);
	return (0);
}