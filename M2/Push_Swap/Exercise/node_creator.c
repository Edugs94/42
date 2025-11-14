/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:23:54 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/14 13:09:16 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*atoi_args(int argc, char **argv)
{
	int		*arr;
	size_t	i;

	i = 0;
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*iter;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	iter = *lst;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = new;
}

void	add_index(t_stack **stack, int size)//asignamos el orden final a cada elemento del nodo
{
	size_t	i;
	long	last;
	t_stack	*min;
	t_stack	*iteri;

	i = 0;
	if (!stack || size <= 1)
		return ;
	last = LONG_MIN;
	while (i < size)
	{
		iteri = *stack;
		min = *stack;
		while (iteri->next)
		{
			iteri = iteri->next;
			if (iteri->content > last && iteri->content < min->content)
				min = iteri;
		}
		min->index = i;
		last = min->content;
		i++;
	}
}

t_stack	*stack(int size, int *argv)//queremos devolver el primer elemento de la lista
{
	t_stack	*stack;
	t_stack	*new_node;
	size_t	i;

	i = 0;
	stack = ft_lstnew(ft_atoi(argv[i]));
	i++;
	while (i < size)
	{
		new_node = ft_lstnew(argv[i]);
		ft_add_back(&stack, new_node);
		i++;
	}
	return (stack);
}
