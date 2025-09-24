/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:03:27 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/24 12:10:55 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	i;
	int	*str;

	len = max - min;
	if (len <= 0)
		return (NULL);
	str = (int *)malloc(sizeof(int) * len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = min;
		min++;
		i++;
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	int	*str;
	int	min;
	int	max;
	int	i;

	if (argc < 3)
		return (-1);
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	str = ft_range(min, max);
	i = 0;
	while(str[i])
	{
		printf("%d\n", str[i]);
		i++;	
	}
	return (0);
}
*/
