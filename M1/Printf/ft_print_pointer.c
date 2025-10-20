/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:01 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 16:52:38 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int	ft_hex_len(unsigned long n)
{
	unsigned int	hex_len;

	hex_len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		hex_len++;
	}
	return (hex_len);
}

static char	ft_hex_char(unsigned long nb)
{
	char	c;
	char	*str;

	str = "0123456789abcdef";
	c = str[nb % 16];
	return (c);
}

static char	*ft_itoa_hex(unsigned long n)
{
	char			*str;
	unsigned int	hex_len;
	unsigned long	nb;

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
	char			*str;
	unsigned int	str_len;
	unsigned long	adress;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	adress = (unsigned long)ptr;
	str = ft_itoa_hex(adress);
	write(1, "0x", 2);
	str_len = ft_print_str(str);
	free(str);
	return (2 + str_len);
}
