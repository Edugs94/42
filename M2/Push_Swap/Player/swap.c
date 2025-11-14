/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* swap.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/11/12 14:51:16 by egalindo          #+#    #+#             */
/* Updated: 2025/11/14 17:00:00 by Gemini          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	// Corregido: t_list -> t_stack
	t_stack	*ptr1;
	t_stack	*ptr2;

	// Corregido: Comprobar si hay al menos 2 elementos
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
	printf("sa\n"); // Corregido: ft_printf -> printf
}

void	ft_sb(t_stack **stack)
{
	ft_swap(stack);
	printf("sb\n"); // Corregido: ft_printf -> printf
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a); // No llama a ft_sa para no imprimir doble
	ft_swap(stack_b); // No llama a ft_sb
	printf("ss\n"); // Corregido: ft_printf -> printf (y añadido \n)
}