/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:22:55 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/15 15:40:43 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (!*stack || !(*stack)->next)
		return ;
	ptr1 = *stack;
	ptr2 = ptr1->next;
	ptr1->next = ptr2->next;
	ptr2->next = ptr1;
	*stack = ptr2;
}

void	ft_sa(t_stack **stack)
{
	ft_swap(stack);
	printf("sa\n");
}

void	ft_sb(t_stack **stack)
{
	ft_swap(stack);
	printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}
