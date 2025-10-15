/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/15 11:22:43 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

char	*ft_itoa_hex(unsigned long n)
{
	char			*str;
	unsigned int	hex_len;
	unsigned int	nb;

	nb = n;
	hex_len = ft_hex_len(n);
	str = (char *)malloc(sizeof(char) * hex_len + 1);
	if (str == NULL)
		return (NULL);
	str[hex_len] = '\0';
	hex_len--;
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[hex_len] = ft_hex_char(nb);
		nb = nb / 16;
		hex_len--;
	}
	return (str);
}

unsigned int	ft_print_pointer(void *ptr)
{
	char	*str;

	if (!ptr)
		return (write(1, "(nil)", 5));
	str = ft_itoa_hex((unsigned long)ptr);
	return (write(1, "0x", 2) + ft_print_str(str));
}

unsigned int	ft_print_low_hex(unsigned long n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = ft_itoa_hex(n);
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (ft_print_str(str));
}

unsigned int	ft_print_hex(unsigned long n)
{
	char	*str;

	str = ft_itoa_hex(n);
	return (ft_print_str(str));
}
