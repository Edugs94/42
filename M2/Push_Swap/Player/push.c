/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* push.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/11/13 18:04:12 by egalindo          #+#    #+#             */
/* Updated: 2025/11/14 17:00:00 by Gemini          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

// Tu lógica de push está bien
void	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*ptr;

	if (!*stack_from) // No hacer nada si el origen está vacío
		return ;
	ptr = *stack_from; // Guardar el primer nodo de 'from'
	*stack_from = (*stack_from)->next; // 'from' apunta al segundo
	if (!*stack_to) // Si 'to' está vacío
	{
		*stack_to = ptr;
		(*stack_to)->next = NULL;
	}
	else // Si 'to' no está vacío
	{
		ptr->next = *stack_to; // El nodo movido apunta al primero de 'to'
		*stack_to = ptr; // 'to' apunta al nodo movido
	}
}

// ft_pa(A, B) -> Push A B -> ft_push(B, A)
void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	printf("pa\n"); // Corregido: ft_printf -> printf
}

// ft_pb(A, B) -> Push B A -> ft_push(A, B)
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	printf("pb\n"); // Corregido: ft_printf -> printf
}