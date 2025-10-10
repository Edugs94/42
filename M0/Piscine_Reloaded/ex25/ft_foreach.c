/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:48:02 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/24 13:19:50 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }

    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }

    if (n >= 10)
        ft_putnbr(n / 10);

    ft_putchar(n % 10 + '0');
}
*/
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
int	main(void)
{
	int	str[] = {3, 4, 5, 6, 7};
	int	len = 5;
	ft_foreach(str, len, &ft_putnbr);
	return(0);
}
*/
