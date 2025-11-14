/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:04:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/14 14:49:32 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*ptr;

	if (!*stack_2)
	{
		*stack_2 = *stack_1;
		*stack_1 = *stack_1->next;
		*stack_2->next = NULL;
	}
	else
	{
		ptr = *stack_1;
		*stack_1 = *stack_1->next;
		ptr->next = *stack_2;
		*stack_2 = ptr;
	}
}

void	ft_pa(t_stack **stack_1, t_stack **stack_2)
{
	ft_push(stack_2, stack_1);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **stack_1, t_stack **stack_2)
{
	ft_push(stack_1, stack_2);
	ft_printf("pb\n");
}
