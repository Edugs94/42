/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/15 16:11:03 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int	ft_hex_len(unsigned long n)
{
	unsigned int	hex_len;

	hex_len = 0;
	while (n > 0)
	{
		n = n / 16;
		hex_len++;
	}
	return (hex_len);
}
static char	ft_hex_char(unsigned int nb)
{
	char	c;
	char	str[17];

	ft_strlcpy(str, "0123456789ABCDEF", 17);
	c = str[nb % 16];
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

unsigned int	ft_print_low_hex(unsigned long n)
{
	unsigned int	i;
	char			*str;
	unsigned int	str_len;

	i = 0;
	str = ft_itoa_hex(n);
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}

unsigned int	ft_print_hex(unsigned long n)
{
	char	*str;
	unsigned int	str_len;

	str = ft_itoa_hex(n);
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}
