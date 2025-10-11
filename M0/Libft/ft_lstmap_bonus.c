/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:53:41 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/11 22:14:59 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_node = ft_lstnew((*f)(lst->content));
	if (new_node == NULL)
		return (NULL);
	first_node = new_node;
	last_node = first_node;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		last_node->next = new_node;
		last_node = last_node->next;
		lst = lst->next;
	}
	return (first_node);
}
