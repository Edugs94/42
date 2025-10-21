/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:17:47 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/21 17:21:06 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_print_specifier(char specifier, unsigned long arg)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = ft_print_char((int)arg);
	else if (specifier == 's')
		len = ft_print_str((char *)arg);
	else if (specifier == 'p')
		len = ft_print_pointer((void *)arg);
	else if (specifier == 'd' || specifier == 'i')
		len = ft_print_integer((int)arg);
	else if (specifier == 'u')
		len = ft_print_unsigned((unsigned int)arg);
	else if (specifier == 'x')
		len = ft_print_hex((unsigned int)arg);
	else if (specifier == 'X')
		len = ft_print_upper_hex((unsigned int)arg);
	return (len);
}

static int	ft_isformat(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	else if (c == 'i' || c == 'u'|| c == 'x' || c == 'X')
		return (1);
	else if (c == '%')
		return (2);
	else
		return (0);
}

static int	ft_check(char const *format, unsigned int *i, unsigned long arg)
{
	int	len;

	*i = *i + 1;
	len = 0;
	len = ft_print_specifier(format[*i], arg);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	int				len;
	int				check;
	unsigned long	ulong;

	i = 0;
	len = 0;
	va_start (args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && (!format[i + 1] || format[i + 1] == ' '))
			return (-1);
		else if (format[i] == '%' && ft_isformat(format[i + 1]) == 1)
		{
			ulong = va_arg(args, unsigned long);
			check = ft_check(format, &i, ulong);
			if (check < 0)
				return (-1);
			len += check;
		}
		else if(format[i] == '%' && ft_isformat(format[i + 1]) == 2)
		{
			len += write(1, "%", 1);
			i++;
		}
		else if(format[i] == '%' && ft_isformat(format[i + 1]) == 0)
		{
			if (ft_isalpha(format[i + 1])> 0)
			{
				len += write(1, &format[i++], 1);
				len += write(1, &format[i], 1);
			}
			else
			{
				write(1, &format[i++], 1);
				write(1, &format[i], 1);
			}
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
