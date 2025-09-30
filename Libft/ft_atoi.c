/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:51:30 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/30 19:07:11 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi(const char *nptr)
{
	int		sign;
	size_t	i;
	size_t	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while(nptr[i] == ' ')
		i++;
	if(nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = nbr * 10 + (nptr[i] + 48);
		i++;
	}
	return (nbr * sign);
}
