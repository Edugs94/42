/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:52 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 14:08:49 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

unsigned int	ft_print_integer(int n)
{
	char			*str;
	unsigned int	str_len;

	str = ft_itoa(n);
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}
