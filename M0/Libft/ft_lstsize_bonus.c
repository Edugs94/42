/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:27:11 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/10 17:41:00 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*iter;

	if (!lst)
		return (NULL);
	iter = lst;
	while (iter != NULL)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
