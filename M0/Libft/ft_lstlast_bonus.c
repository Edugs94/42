/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:41:21 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/11 14:34:52 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	if (!lst)
		return (0);
	iter = lst;
	while (iter != NULL || iter->next != NULL)
		iter = iter->next;
	return (iter);
}
