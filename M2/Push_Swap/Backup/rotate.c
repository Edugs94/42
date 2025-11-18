/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:40:04 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/14 14:42:15 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*iteri;
	t_stack	*last;

	iteri = *stack;
	first = *stack;
	while (iteri->next)
		iteri = iteri->next;
	if (*stack->next)
		*stack = stack->next;
	else
		return ;
	first->next = NULL;
	iteri->next = first;
	*stack = iteri;
}

void	ft_ra(t_stack **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_1, t_stack **stack_2)
{
	ft_rotate(stack_1);
	ft_rotate(stack_2);
	ft_printf("rr\n");
}
