/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_validate_and_parse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:49:30 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/18 23:22:33 by edu-legion       ###   ########.fr       */
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
	
	//free(clean_data);
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