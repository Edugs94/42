/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:22:02 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/15 18:55:11 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checker(t_stack *stack_a, int size)
{
	t_stack *iteri;
	int i;

	if (!stack_a)
		return (-1);
	iteri = stack_a;
	i = 0;
	if (size == 1)
		return (0);
	while (iteri->next)
	{
		if (iteri->content < iteri->next->content)
		{
			iteri = iteri->next;
			i++;
		}
		else
			return (-2);
	}
	if (i != size - 1)
		return (-3);
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	t_stack *stack_a;
	t_stack *stack_b;

	step = 0;
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
		/*
		if (strcmp(order, "sa") == 0)
			ft_sa(&stack_a);
		else if (strcmp(order, "sb") == 0)
			ft_sb(&stack_b);
		else if (strcmp(order, "ss") == 0)
			ft_ss(&stack_a, &stack_b);
		else if (strcmp(order, "pa") == 0)
			ft_pa(&stack_a, &stack_b);
		else if (strcmp(order, "pb") == 0)
			ft_pb(&stack_a, &stack_b);
		else if (strcmp(order, "ra") == 0)
			ft_ra(&stack_a);
		else if (strcmp(order, "rb") == 0)
			ft_rb(&stack_b);
		else if (strcmp(order, "rr") == 0)
			ft_rr(&stack_a, &stack_b);
		else if (strcmp(order, "rra") == 0)
			ft_rra(&stack_a);
		else if (strcmp(order, "rrb") == 0)
			ft_rrb(&stack_b);
		else if (strcmp(order, "rrr") == 0)
			ft_rrr(&stack_a, &stack_b);
		else
			valid_move = 0;
		if (valid_move)
			step++;
	}
	system("clear");
	iteri_a = stack_a;
	iteri_b = stack_b;
	printf("\n--- Step %d ---\n", step);
		printf("Stack A: Stack B:\n");
		printf("------- -------\n");
		while (iteri_a || iteri_b)
		{
			if (iteri_a)
			{
				printf("%-11d", iteri_a->content);
				iteri_a = iteri_a->next;
			}
			else
				printf("           ");
			if (iteri_b)
			{
				printf("%d\n", iteri_b->content);
				iteri_b = iteri_b->next;
			}
			else
				printf("\n");
		}
	printf("---------------------\n");
	printf("Game passed on %d steps!\n", step);
	printf("                   \n");
    printf(" Yuuuhuuuuuuuu!\n");
    printf("              (   ()   )\n");
    printf("    ) ________    //  )\n");
    printf(" ()  |\\       \\  //\n");
    printf("( \\\\__ \\ ______\\\\//\n");
    printf("   \\__) |       |\n");
    printf("     |  |       |\n");
    printf("      \\ |       |\n");
    printf("       \\|_______|\n");
    printf("       //    \\\\\n");
    printf("      ((     ||\n");
    printf("       \\\\    ||\n");
    printf("     ( ()    ||\n");
    printf("      (      () ) )\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(int_arr);*/
	return (0);
}
