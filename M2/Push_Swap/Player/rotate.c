/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* rotate.c                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/11/14 09:40:04 by egalindo          #+#    #+#             */
/* Updated: 2025/11/14 17:00:00 by Gemini          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ft_ra(t_stack **stack)
{
	ft_rotate(stack);
	printf("ra\n");
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	printf("rb\n");
}

void	ft_rr(t_stack **stack_1, t_stack **stack_2)
{
	ft_rotate(stack_1);
	ft_rotate(stack_2);
	printf("rr\n");
}