/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:10:31 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/08 14:57:32 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow_10(int n)
{
	int		i;
	size_t	pow;

	pow = 1;
	i = 0;
	while (i < n)
	{
		pow = pow * 10;
		i++;
	}
	return (pow);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;
	int		nb;

	len = 0;
	i = 0;
	nb = n;
	if (n < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}
// a partir de aqui no me sale, si hago 50832, el 0832 se me quedara colgado, es mejor hacerlo de alante a atras con recursividad??
	while (n > 0)
	{
		str[i] = (n / ft_pow_10(j)) + 48;
		i++;
	}
	str[i] = '\0';
	return (str);
}
