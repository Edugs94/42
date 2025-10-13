/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 07:41:43 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/13 18:00:19 by egalindo         ###   ########.fr       */
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
		sum = number + sum;
		i++;
	}
	va_end (args);
	return (sum);
}

int main() 
{
	char	str[4] = "hola";
    printf("el valor es %p\n", str);
    printf("Probando: \"\n");
    return 0;
}
