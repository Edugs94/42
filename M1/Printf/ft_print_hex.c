/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 16:02:00 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_hex_len(unsigned int n)
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

static char	ft_hex_char(unsigned int nb)
{
	char	c;
	char	*str;

	str = "0123456789abcdef";
	c = str[nb % 16];
	return (c);
}

static char	*ft_itoa_hex(unsigned int n)
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

int	ft_print_upper_hex(unsigned int n)
{
	unsigned int	i;
	char			*str;
	unsigned int	str_len;

	i = 0;
	str = ft_itoa_hex(n);
	if (!str)
		return (-1);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}

int	ft_print_hex(unsigned int n)
{
	char			*str;
	unsigned int	str_len;

	str = ft_itoa_hex(n);
	if (!str)
		return (-1);
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}
