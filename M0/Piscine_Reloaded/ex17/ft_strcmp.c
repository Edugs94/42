/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:52:05 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/22 18:12:49 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && ((s1[i] || s2[i])))
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(int argc, char **argv)
{
	int	result;

	(void)argc;
	result = ft_strcmp(argv[1], argv[2]);
	printf ("%d", result);
	return (0);
}
*/
