/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:38:12 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/14 17:13:10 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_hex_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_str(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_print_number(int n)
{
	char	*str;

	str = ft_itoa(n);
	if (str == NULL)
		return (NULL);
	ft_printstr(str);
	return (ft_strlen(str));
}
