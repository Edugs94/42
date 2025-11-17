/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:22:02 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/17 11:58:56 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checker(t_stack *stack_a, int size)
{
	t_stack *iteri;
	int i;

	if (!stack_a)
		exit(1);
	iteri = stack_a;
	i = 0;
	if (size == 1)
		exit(0);
	while (iteri->next)
	{
		if (iteri->content < iteri->next->content)
		{
			iteri = iteri->next;
			i++;
		}
		else
			exit(2);
	}
	if (i != size - 1)
		exit(3);
	exit(0);
}

int main(int argc, char **argv)
{
	int 	i;
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc <= 2)
	{
		printf("Error\n");
		return (-1);
	}
	stack_a = create_stack(argc - 1, int_arr);
	if (!stack_a)
		return NULL;
	add_index(&stack_a, argc - 1);
	stack_b = NULL;
	ft_turk(&stack_a, &stack_b, argc - 1);
	return (0);
}
