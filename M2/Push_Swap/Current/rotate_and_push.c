/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:48:13 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/19 18:20:41 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_rotation(t_stack *node, t_stack **stack)
{
	int	position;
	int	size;

	position = ft_node_position(node, *stack);
	size = ft_lstsize(*stack);
	if (position <= size / 2)
		return (position);
	else
		return (-position + size);
}

void	rotate_and_push(t_stack *min, t_stack **stack_a, t_stack **stack_b)
{
	int	moves;

	moves = cheapest_rotation(min, stack_b);
	while (moves != 0)
	{
		if (moves > 0)
		{
			ft_rb(stack_b);
			moves--;
		}
		if (moves < 0)
		{
			ft_rrb(stack_b);
			moves++;
		}
	}
	moves = cheapest_rotation(min->target, stack_a);
	while (moves != 0)
	{
		if (moves > 0)
		{
			ft_ra(stack_a);
			moves--;
		}
		if (moves < 0)
		{
			ft_rra(stack_a);
			moves++;
		}
	}
	ft_pa(stack_a, stack_b);
}
