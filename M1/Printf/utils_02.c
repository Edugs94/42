/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/14 17:16:50 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//#include "libft.h"

static char	ft_hex_char(unsigned int nb)
{
	char	c;

	c = '\0';
	if (nb % 16 < 10)
		c = (nb % 16) + '0';
	if (nb % 16 == 10)
		c = 'A';
	if (nb % 16 == 11)
		c = 'B';
	if (nb % 16 == 12)
		c = 'C';
	if (nb % 16 == 13)
		c = 'D';
	if (nb % 16 == 14)
		c = 'E';
	if (nb % 16 == 15)
		c = 'F';
	return (c);
}

char	*ft_itoa_hex(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	nb = n;
	len = ft_hex_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[len] = ft_hex_char(nb);
		nb = nb / 16;
		len--;
	}
	return (str);
}

int	ft_print_pointer(unsigned int *ptr)
{
	char	*str;

	if (!ptr)
		return (NULL);
	str = ft_itoa_hex((unsigned int)ptr);
	if (!str)
		return (NULL);
	write(1, "0x", 2);
	ft_print_str(str);
	return (ft_strlen(str) + 2);
}

int	ft_print_low_hex(unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = ft_itoa_hex(n);
	if (!str)
		return (NULL);
	while (str[i])
		str[i] = ft_tolower(str[i]);
	ft_print_str(str);
	return (ft_strlen(str));
}

int	ft_print_hex(unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = ft_itoa_hex(n);
	if (!str)
		return (NULL);
	ft_print_str(str);
	return (ft_strlen(str));
}
