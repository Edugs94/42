/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/15 18:44:20 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

unsigned int	ft_print_pointer(void *ptr)
{
	char	*str;
	unsigned int	str_len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	str = ft_itoa_hex((unsigned long)ptr);
	str_len = ft_print_str(str);
	free(str);
	return (write(1, "0x", 2) + str_len);
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
	unsigned int	str_len;

	str = ft_itoa(n);
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}
