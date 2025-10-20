/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 23:27:35 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 15:59:46 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf(" %p ", (void *)-1);
	ft_printf("\n");
	ft_printf(" %p ", (void *)15);
	ft_printf("\n");
	ft_printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("\n");
	ft_printf(" %p %p ", (void *)INT_MIN, (void *)INT_MAX);
	ft_printf("\n");
	ft_printf(" %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	ft_printf("\n");

	ft_printf(" %x ", -1);
	ft_printf("\n");
	ft_printf(" %x ", 15);
	ft_printf("\n");
	ft_printf(" %x ", -9);
	ft_printf("\n");
	ft_printf(" %x ", -10);
	ft_printf("\n");
	ft_printf(" %x ", -11);
	ft_printf("\n");
	ft_printf(" %x ", -14);
	ft_printf("\n");
	ft_printf(" %x ", -15);
	ft_printf("\n");
	ft_printf(" %x ", -16);
	ft_printf("\n");
	ft_printf(" %x ", -99);
	ft_printf("\n");
	ft_printf(" %x ", -100);
	ft_printf("\n");
	ft_printf(" %x ", -101);
	ft_printf("\n");
	ft_printf(" %x ", INT_MAX);
	ft_printf("\n");

	
	return (0);
}
