/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:24:49 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/24 17:32:23 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	if (nb > 12)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
int	main(int argc, char **argv)
{
	int	nb;
	int	result;
	(void)argc;
	nb = atoi(argv[1]);
	result = ft_recursive_factorial(nb);
	printf("%d\n", result);
	return (0);
}
*/
