/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:11:46 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/10 12:26:30 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	x;
	char	y;

	x = 'P';
	y = 'N';
	if (n >= 0)
	{
		write (1, &x, 1);
	}
	else
	{
		write (1, &y, 1);
	}
}
/*
int	main(void)
{
	ft_is_negative(-6);
	return (0);
}
*/
