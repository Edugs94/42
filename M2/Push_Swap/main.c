/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:49:30 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/19 18:08:42 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*clean_data;
	int	size;
	int	i;

	i = 0;
	clean_data = validate_and_parse(argc, argv, &size);
	stack_and_sort(clean_data, size);
	free(clean_data);
	return (0);
}

/* -- main for parse check
int	main(int argc, char **argv)
{
	int	*clean_data;
	int	size;
	int	i;

	i = 0;
	clean_data = validate_and_parse(argc, argv, &size);
	while (i < size)
	{
		printf("%d\n", clean_data[i]);
		i++;
	}
	free(clean_data);
	return (0);
}
*/
