/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:21:21 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/10 18:44:06 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	unsigned int	i;
	t_list			*iter;

	if (!lst || !new)
		return (NULL);
	iter = lst;
	while (iter != NULL)
		iter = iter->next;
	new = iter;
}
