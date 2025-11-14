/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* reverse_rotate.c                                   :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/11/14 09:40:04 by egalindo          #+#    #+#             */
/* Updated: 2025/11/14 17:00:00 by Gemini          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack **stack)
{
	t_stack	*iteri;
	t_stack	*last;

	// Corregido: Comprobación más segura
	if (!*stack || !(*stack)->next)
		return ;
		
	iteri = *stack; // Será el último
	last = *stack; // Será el penúltimo

	while (iteri->next)
		iteri = iteri->next;
	while (last->next != iteri)
		last = last->next;
		
	last->next = NULL; // El penúltimo apunta a NULL
	iteri->next = *stack; // El último apunta al primero
	*stack = iteri; // El stack apunta al (antiguo) último
}

void	ft_rra(t_stack **stack)
{
	ft_rrotate(stack);
	printf("rra\n"); // Corregido: ft_printf -> printf
}

void	ft_rrb(t_stack **stack)
{
	ft_rrotate(stack);
	printf("rrb\n"); // Corregido: ft_printf -> printf
}

void	ft_rrr(t_stack **stack_1, t_stack **stack_2)
{
	ft_rrotate(stack_1);
	ft_rrotate(stack_2);
	printf("rrr\n"); // Corregido: ft_printf -> printf
}