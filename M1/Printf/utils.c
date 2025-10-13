/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/13 18:48:56 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_hex(int n)
{
	long long	nb;
	char		c;

	nb = n;
	if (nb >= 10)
		ft_print_hex(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long long	nb;
	char		c;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_print_str(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_pointer(char *ptr)
{
	write(1, "0x", 2);
	ft_print_hex((int)ptr);
}
