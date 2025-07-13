/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:57:30 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/13 12:50:37 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_write_values(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
}

void	ft_comma_and_space(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	cd_loop(char a, char b, char c, char d)
{
	while (!(c == '9' && d == '9'))
	{
		if (a < c || (a == c && b < d))
		{
			ft_write_values(a, b, c, d);
			ft_comma_and_space();
		}
		if (d < '9')
			d ++;
		else
		{
			d = '0';
			c ++;
		}
	}
	if (a < c || (a == c && b < d))
	{
		ft_write_values(a, b, c, d);
		if (!(a == '9' && b == '8' && c == '9' && d == '9'))
			ft_comma_and_space();
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	while (!(a == '9' && b == '9'))
	{
		c = '0';
		d = '0';
		cd_loop (a, b, c, d);
		if (b < '9')
		{
			b ++;
		}
		else
		{
			b = '0';
			a ++;
		}
	}
}
/*
int	main(void)
{
	ft_print_comb2();
}
*/
