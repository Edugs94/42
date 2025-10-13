/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:17:47 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/13 18:49:27 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void	ft_print_specifier(char c)
{
	if (c == 'c')  // char
		write(1, /*placeholder*/, 1);
	if (c == 's') // string
		ft_print_str(/*placeholder*/);
	if (c == 'p') // direccion de memoria de un puntero
		ft_print_pointer(/*placeholder*/);
	if (c == 'd' || c == 'i')//integer
		ft_putnbr(/*placeholder*/);
	if (c == 'u')
		return ;
	if (c == 'x')
		return ;
	if (c == '%')
		write(1, "%", 1);;
}

int printf(const char *format, ...)
{
	unsigned char	i;

	i = 0;
	while(str[i])
	{
		if (ft_isprint(str[i]) > 0 && str[i] != '%')
		{
			if (str[i - 1] != '%' && ft_isspecifier(str[i]) == 1)
				ft_print_specifier(str[i]);
			// revisar si despuede % no va un format reconocido, como reacciona la funcion oficial?
			if (str[i - 1] != '%' && ft_isspecifier(str[i]) == 0)
				ft_print_specifier(str[i]);
			else
				write(1, &str[i], 1);
		}
		i++;
	}
}
