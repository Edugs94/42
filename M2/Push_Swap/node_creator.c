/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:23:54 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/13 19:33:41 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*atoi_args(int argc, char **argv)
{
	int		*arr;
	size_t	i;

	i = 0
	while(i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iter;

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

t_list  *create_list(int size, int *argv)//queremos devolver el primer elemento de la lista
{
	t_list  *begin_list;
	t_list  *new_node;
	size_t  i;

	i = 0;
	begin_list = ft_lstnew(ft_atoi(argv[i]));
	i++;
	while (i < size)
	{
		new_node = ft_lstnew(argv[i]);
		ft_add_back(&begin_list, new_node);
		i++;
	}
	return (begin_list);
}
