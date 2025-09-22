/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:21:04 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/22 16:52:07 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/*
int main (int argc, char **argv)
{
	int	nb;
	int	result;
	(void)argc;

	nb = atoi (argv[1]);
	result = ft_sqrt(nb);
	printf("%d", result);
	return (0);
}
*/
