/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:17:47 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 20:20:36 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_print_specifier(char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		len = ft_print_pointer(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		len = ft_print_integer(va_arg(args, int));
	else if (specifier == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		len = ft_print_hex(va_arg(args, unsigned int));
	else if (specifier == 'X')
		len = ft_print_upper_hex(va_arg(args, unsigned int));
	return (len);
}

static int	ft_check_next(char const *format, unsigned int *i, va_list args)
{
	int	len;

	*i = *i + 1;
	len = 0;
	if (format[*i] == '%')
	{
		len = write(1, "%", 1);
		return (len);
	}
	len = ft_print_specifier(format[*i], args);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	int				len;

	i = 0;
	len = 0;
	va_start (args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_check_next(format, &i, args);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
