/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:47:31 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/10 15:39:27 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (0);
	if (nmemb > INT_MAX / size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (0);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
