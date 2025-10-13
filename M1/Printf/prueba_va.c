/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 07:41:43 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/13 11:18:02 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_sum(unsigned int count, ...)
{
	int				sum;
	int				number;
	unsigned int	i;

	sum = 0;
	i = 0;
	va_list	args;
	va_start(args, count);
	while(i < count)
	{
		number = va_arg(args, int);
		i++;
	}
	va_end (args);
	return (number);
}

int main() 
{
    printf("La suma es: %d\n", ft_sum(4, 10, 20, 30, 5)); // Resultado: 65
    return 0;
}
