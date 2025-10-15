/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 23:27:35 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/15 23:27:35 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// Prueba que causaría el error original
	ft_printf("String: %s\n", "Esto es un test\n");
	printf("String: %s\n", "Esto es un test\n");
	
	// Prueba con memoria alocada
	ft_printf("Numero: %d\n", 42);
	printf("Numero: %d\n", 42);
	ft_printf("Hex: %X\n", 12345);
	printf("Hex: %X\n", 12345);
	
	return (0);
}