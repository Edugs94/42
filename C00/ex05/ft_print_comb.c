/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:56:25 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/11 12:31:27 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

void	ft_print(int a, int b, int c)
{
	if (a < b && b < c)
	{
		ft_write (a + '0');
		ft_write (b + '0');
		ft_write (c + '0');
		if (!(a == 7 && b == 8 && c == 9))
		{
			ft_write (',');
			ft_write (' ');
		}
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			c = 0;
			while (c <= 9)
			{
				ft_print(a, b, c);
				c ++;
			}
			b ++;
		}
		a ++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
