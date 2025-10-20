/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:13 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 14:08:38 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

unsigned int	ft_print_str(char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
