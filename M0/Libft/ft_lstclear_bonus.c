/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:15:52 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/11 17:31:19 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*curr;

	if (*lst == NULL || lst == NULL)
		return ;
	iter = *lst;
	while (iter)
	{
		curr = iter;
		iter = iter->next;
		del(curr->content);
		free(curr);
	}
	*lst = NULL;
}
