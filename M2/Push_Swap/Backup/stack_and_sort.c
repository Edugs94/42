/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_and_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:26:58 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/19 14:56:28 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_index(t_stack **stack, int size)
{
	int		i;
	long	last;
	t_stack	*min;
	t_stack	*iteri;

	i = 0;
	if (!stack || !*stack || size <= 0)
		return ;
	last = LONG_MIN;
	while (i < size)
	{
		iteri = *stack;
		min = NULL;
		while (iteri)
		{
			if (iteri->content > last && iteri->index == 0)
			{
				min = iteri;
				break;
			}
			iteri = iteri->next;
		}
		iteri = *stack;
		while (iteri)
		{
			if (iteri->content > last && iteri->content < min->content 
				&& iteri->index == 0)
				min = iteri;
			iteri = iteri->next;
		}

		if (min)
		{
			min->index = i;
			last = min->content;
		}
		i++;
	}
}

void	stack_and_sort(int *clean_data, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack(clean_data, size);
	add_index(&stack_a, size);
	stack_b = NULL;
	turk_algorithm(&stack_a, &stack_b, size);
	//free everything
}
