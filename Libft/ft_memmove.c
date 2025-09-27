/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:47:23 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/27 15:09:31 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < n)
	{
		temp[i] = (char *)src;
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = tepmp[i];
		i++;
	}
}
