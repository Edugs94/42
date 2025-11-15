/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:19:59 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/15 18:49:17 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	*atoi_args(int size, char **argv)
{
	int		*arr;
	int		i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (size));
	if (arr == NULL)
		return (NULL);
	while (i < size)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

void	add_index(t_stack **stack, int size)
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

t_stack	*create_stack(int size, char **argv)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		*int_arr;
	int		i;

	if (size <= 0 )
		return (NULL);
	i = 0;
	int_arr = atoi_args(size, argv);
	if (!int_arr)
		return (NULL);
	stack = ft_lstnew(int_arr[i]);
	i++;
	while (i < size)
	{
		new_node = ft_lstnew(int_arr[i]);
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}
