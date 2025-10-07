/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:06:32 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/07 18:13:11 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;
	char	*str;

	i = 0;
	count = 0;
	while (ft_strchr(set, s1[i]) != 0 && s1[i])
	{
		i++;
		count++;
	}
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) != 0 && i > 0)
	{
		i--;
		count++;
	}
	str = (char *)malloc(count + 1);
	if (str == NULL)
		return (0);
	while (ft_strchr(set, s1[i]) != 0)
		i++;
	while (j < count)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}
