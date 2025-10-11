/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:27:11 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/11 14:34:22 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
