/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/15 11:22:27 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

unsigned int	ft_hex_len(unsigned int n)
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

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

unsigned int	ft_print_str(char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

unsigned int	ft_print_number(long long n)
{
	char	*str;

	str = ft_itoa(n);
	return (ft_print_str(str));
}
