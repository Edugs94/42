/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:34:01 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/18 15:03:26 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_and_exit(int error, char **matrix, int *int_arr)
{
	printf("Error\n");
	if (error == 1)
		exit (1);
	if (error == 2)
	{
		free(matrix);
		exit(2);
	}
	if (error == 3)
	{
		free(matrix);
		free(int_arr);
		exit(3);
	}
}
