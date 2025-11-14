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

int	reorder_list(int **array, unsigned int size, char *operator)
{
	if (ft_strncmp(operator, "sa", ft_strlen(operator)))
		return (ft_sa(array, size), 0);
	if (ft_strncmp(operator, "sb", ft_strlen(operator)))
		return (ft_sb(array, size), 0);
	if (ft_strncmp(operator, "ss", ft_strlen(operator)))
		return (ft_ss(array, size), 0);
	if (ft_strncmp(operator, "pa", ft_strlen(operator)))
		return (ft_pa(array, size), 0);
	if (ft_strncmp(operator, "pb", ft_strlen(operator)))
		return (ft_pb(array, size), 0);
	if (ft_strncmp(operator, "ra", ft_strlen(operator)))
		return (ft_ra(array, size), 0);
	if (ft_strncmp(operator, "rb", ft_strlen(operator)))
		return (ft_rb(array, size), 0);
	if (ft_strncmp(operator, "rr", ft_strlen(operator)))
		return (ft_rr(array, size), 0);
	if (ft_strncmp(operator, "rra", ft_strlen(operator)))
		return (ft_rra(array, size), 0);
	if (ft_strncmp(operator, "rrb", ft_strlen(operator)))
		return (ft_rrb(array, size), 0);
	if (ft_strncmp(operator, "rrr", ft_strlen(operator)))
		return (ft_rrr(array, size), 0);
	else
		return (-1);
}

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
