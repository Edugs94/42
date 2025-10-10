/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:25:32 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/24 17:30:39 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb < 0)
		result = 0;
	if (nb == 0)
		result = 1;
	if (nb > 12)
		return (0);
	while (nb > 1)
	{
		result = result * (nb - 1);
		nb--;
	}
	return (result);
}

/*
int	main(int argc, char **argv)
{
	int	nb;
	int	result;
	(void)argc;
	nb = atoi(argv[1]);
	result = ft_iterative_factorial(nb);
	printf("%d\n", result);
}
*/
