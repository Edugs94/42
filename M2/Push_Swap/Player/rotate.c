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

// ¡¡FUNCIÓN COMPLETAMENTE CORREGIDA!!
// Mueve el primer elemento al final.
void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	// No se puede rotar si hay 0 o 1 elemento
	if (!*stack || !(*stack)->next)
		return ;
	
	first = *stack; // Guardamos el primer nodo
	*stack = (*stack)->next; // El stack ahora empieza en el segundo
	
	// Buscar el último nodo
	last = *stack;
	while (last->next)
		last = last->next;
	
	// Enganchar el primer nodo al final
	last->next = first;
	first->next = NULL; // El antiguo primero es ahora el último
}

void	ft_ra(t_stack **stack)
{
	ft_rotate(stack);
	printf("ra\n"); // Corregido: ft_printf -> printf
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	printf("rb\n"); // Corregido: ft_printf -> printf
}

void	ft_rr(t_stack **stack_1, t_stack **stack_2)
{
	ft_rotate(stack_1);
	ft_rotate(stack_2);
	printf("rr\n"); // Corregido: ft_printf -> printf
}