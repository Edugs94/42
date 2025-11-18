/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:34:01 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/18 23:31:05 by edu-legion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_and_exit(int error, char **matrix, int *int_arr)
{
	int	i;

	i = 0;
	printf("Error\n");
	if (error == 1)
		exit (1);
	if (error == 2)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
		exit(2);
	}
	if (error == 3)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
		free(int_arr);
		exit(3);
	}
}
