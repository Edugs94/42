/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:46:25 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/11 11:46:25 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}
/*
int	main(int argc, char **argv)
{
	int	n;

	n = 0;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		ft_is_negative(n);
	}
	else
		return (-1);
	return (0);
}
*/