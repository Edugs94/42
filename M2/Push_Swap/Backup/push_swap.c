/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:31:29 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/14 14:13:52 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*int_arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (arg_checker(argc,argv) == -1)//parseo y comprobacion de errores
		return (-1);
	int_arr = atoi_args(argc ,argv);
	stack_a = create_stack(argc, int_arr);
	add_index(stack_a, argc - 1);
	stack_b = NULL;
}
