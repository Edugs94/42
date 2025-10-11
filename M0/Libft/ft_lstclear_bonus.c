/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:15:52 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/11 14:47:53 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;

	if (*lst == NULL || lst == NULL)
		return ;
	while (*lst != NULL)
	{
		iter = *lst;
		*lst = (*lst)->next;
		del(iter->content);
		free(iter);
	}
}
