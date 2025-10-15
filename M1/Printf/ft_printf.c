/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:17:47 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/15 16:23:30 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int	ft_print_specifier(char specifier, va_list args)
{
	unsigned int	len;

	len = 0;
	if (specifier == 'c')
		len = ft_print_char(va_arg(args, int));
	if (specifier == 's')
		len = ft_print_str(va_arg(args, char *));
	if (specifier == 'p')
		len = ft_print_pointer(va_arg(args, void *));
	if (specifier == 'd' || specifier == 'i')
		len = ft_print_number(va_arg(args, long long));
	if (specifier == 'u')
		len = ft_print_number(va_arg(args, unsigned long));
	if (specifier == 'x')
		len = ft_print_low_hex(va_arg(args, unsigned long));
	if (specifier == 'X')
		len = ft_print_hex(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	va_start (args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, "%", 1);
				len++;
				continue ;
			}
			if (format[i] == ' ')
			{
				write(1, " ", 1);
				len++;
				while (format[i])
					i++;
			}
			len = ft_print_specifier(format[i], args) + len;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
