/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:35:29 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/17 12:46:22 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*iter;

	i = 0;
	if (!lst)
		return (0);
	iter = lst;
	while (iter != NULL)
	{
		iter = iter->next;
		i++;
	}
	return (i);
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

int	ft_node_position(t_stack *stack, t_stack *node)
{
	int i;
	t_stack	*iteri;

	i = 0;
	iteri = stack;
	if (!stack || !node)
		exit(1);
	while (iteri != node)
	{
		iteri = iteri->next;
		i++;
	}
	if (iteri == node)
		return (i);
	else
		exit(2);
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
