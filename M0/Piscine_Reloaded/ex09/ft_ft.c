/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:09:11 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/11 12:09:11 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
/*
int	main(int argc, char **argv)
{
	int	n;
	int *nbr;

	nbr = &n;
	(void)argc;
	if (argc > 1)
		n = atoi(argv[1]);
	if (argc <= 1)
		n = 0;
	ft_ft(nbr);
	printf("%d", n);
	return (0);
}
*/