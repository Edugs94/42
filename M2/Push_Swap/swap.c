/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:51:16 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/13 18:59:46 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack) //para sa y sb
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (!**stack || !*stack)
		return ;
	ptr1 = *stack;
	ptr2 = ptr1->next;
	ptr1->next = ptr2-->next;
	ptr2->next = ptr1;
	*stack = ptr2;
}

void	ft_sa(t_stack **stack)
{
	ft_swap(stack);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack)
{
	ft_swap(stack);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_printf("ss");
}
