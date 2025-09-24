/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:48:02 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/24 15:28:14 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
/*
int	ft_strlen_even(char *str)
{
	return (1);
}
*/
int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
		{
			count++;
		}
		i++;
	}
	return (count);
}
/*
int	main(int argc, char **argv)
{
	int	count;

	(void)argc;
	count = ft_count_if(argv, &ft_strlen_even);
	printf("%d", count);
	return(0);
}
*/
