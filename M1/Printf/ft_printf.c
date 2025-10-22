/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:38:20 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/22 21:38:20 by egalindo         ###   ########.fr       */
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

static int	ft_aux_specifier(char spec, va_list args)
{
	int	check;

	if (!spec || spec == ' ')
		return (-1);
	if (spec == '%')
		return (write(1, "%", 1));
	if (ft_strchr("cspdiuxX", spec))
	{
		check = ft_print_specifier(spec, args);
		if (check < 0)
			return (-1);
		return (check);
	}
	return (write(1, "%", 1) + write(1, &spec, 1));
}

static int	iterate_arg(const char *format, int len, va_list args)
{
	int		check;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check = ft_aux_specifier(*format, args);
			if (check < 0)
				return (-1);
			len += check;
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				len;

	va_start (args, format);
	if (!format)
		return (-1);
	len = iterate_arg(format, 0, args);
	va_end(args);
	return (len);
}
