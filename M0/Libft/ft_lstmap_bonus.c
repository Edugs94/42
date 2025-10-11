/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:53:41 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/11 14:30:25 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;
	t_list	*new_node;
	t_list	*init;
	void	*ptr;

	if (!lst)
		return (NULL);
//esta mal porque no estoy reservando espacio para el primero elemento
	iter = lst;
	lst = lst->next;
	ptr = f(iter->content);
	new_node = ft_lstnew(ptr);
	init = new_node;
	while (lst != NULL)
	{
		iter = lst;
		lst = lst->next;
		ptr = f(iter->content);
		new_node = ft_lstnew(ptr);
		ft_lstadd_back(*ptr, new_node);
		ft_lstdelone(iter, del);
	}
	return (init);
}
