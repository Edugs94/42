/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:40:04 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/14 12:04:57 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack **stack)
{
	t_stack	*iteri;
	t_stack	*last;

	iteri = *stack;
	last = *stack;
	if (!*stack->next)
		return ;
	while (iteri->next)
		iteri = iteri->next;
	while (last->next != iteri)
		last = last->next;
	last->next = NULL;
	iteri->next = *stack;
	*stack = iteri;
}

void	ft_rra(t_stack **stack)
{
	ft_rrotate(stack);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack)
{
	ft_rrotate(stack);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_1, t_stack **stack_2)
{
	ft_rrotate(stack_1);
	ft_rrotate(stack_2);
	ft_printf("rrr\n");
}
