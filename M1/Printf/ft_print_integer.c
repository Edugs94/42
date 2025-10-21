/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:52 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 20:25:30 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_integer(int n)
{
	char	*str;
	int		str_len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}
