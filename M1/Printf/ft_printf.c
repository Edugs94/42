/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:17:47 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/14 22:59:38 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned int	ft_print_specifier(char c, unsigned long specifier)
{
	unsigned int	len;

	len = 1;
	if (c == 'c')
		write(1, &specifier, 1);
	if (c == 's')
		len = ft_print_str((char *)specifier);
	if (c == 'p')
		len = ft_print_pointer((void *)specifier);
	if (c == 'd' || c == 'i')
		len = ft_print_number((long long)specifier);
	if (c == 'u')
		len = ft_print_number((unsigned long)specifier);
	if (c == 'x')
		len = ft_print_low_hex((unsigned long)specifier);
	if (c == 'X')
		len = ft_print_hex((unsigned long)specifier);
	if (c == '%')
		write(1, "%", 1);
	return (len);
}

static int	ft_isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == '%')
		return (2);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	void			specifier;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	va_start (args, format);
	if (!format)
		return (NULL);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i] == '%')
			{
				write(1, '%', 1);
				len++;
			}
			i++;
			if (format[i] == ' ')
			{
				write(1, ' ', 1);
				len++;
				while(format[i])
					i++;
			}
					len = ft_print_specifier(format[i], args) + len;
					len++;
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
	

			if (ft_isspecifier(str[i + 1]) == 2)
			{
				write(1, "%", 1);
				i = i + 2;
				len++;
				continue ;
			}
			if (str[i + 1] == ' ')
			{
				write(1, &str[i + 1], 1);
				i++;
				len++;
				while (str[i + 1] == ' ')
					i++;
			}
			if (ft_isspecifier(str[i + 1]) == 1)
			{
				specifier = va_arg(args, unsigned long);
				//cambiar funcion para que reciba tipo 
				//especifico de datos
				ft_print_specifier(str[i + 1], specifier);
				i = i + 2;
				len++;
				continue ;
			}
			if (ft_isspecifier(str[i + 1]) == 0)
			{
				write(1, "%", 1);
				len++;
			}
		}
		else
		{
			write(1, str[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
