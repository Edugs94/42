/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* player_push_swap.c                                 :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/11/14 13:36:40 by egalindo          #+#    #+#             */
/* Updated: 2025/11/14 18:51:03 by Gemini           ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // Añadido para system("clear")

// Checker corregido:
// Comprueba que A esté ordenado y B esté vacío.
int checker(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_stack *iteri;
	int i;

	if (stack_b) // stack_b debe estar vacío
		return (-3);
	if (!stack_a) // stack_a no puede estar vacío (a menos que size=0)
		return (-4);
	iteri = stack_a;
	i = 0;
	while (iteri->next)
	{
		if (iteri->content < iteri->next->content)
		{
			iteri = iteri->next;
			i++;
		}
		else
			return (-1); // No está ordenado
	}
	// Si i == size - 1, significa que hemos hecho size-1 comparaciones
	if (size > 0 && i != size - 1)
		return (-2); // El tamaño no coincide
	if (size == 1 && i == 0) // Caso especial: un solo número
		return (0);
	return (0); // ¡Correcto!
}

int main(int argc, char **argv)
{
	int *int_arr;
	int step;
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *iteri_a;
	t_stack *iteri_b;
	char comando[10]; // ¡Variable 'comando' declarada!

	step = 0;
	if (argc <= 2) // Arreglado el typo 'a'
	{
		printf("Write at least 2 numbers\n");
		return (-1);
	}
	int_arr = atoi_args(argc, argv);
	if (!int_arr) // Comprobar si malloc falló
		return (-1);
	// Corregido: pasar argc - 1 (el tamaño)
	stack_a = create_stack(argc - 1, int_arr);
	// Corregido: pasar la dirección de stack_a
	add_index(&stack_a, argc - 1);
	stack_b = NULL;

	// Corregido: checker ahora recibe stack_b y el tamaño
	while (checker(stack_a, stack_b, argc - 1) != 0)
	{
		system("clear"); // <-- ¡AÑADIDO!

		iteri_a = stack_a;
		iteri_b = stack_b;

		// --- IMPRESIÓN CORREGIDA ---
		printf("\n--- Paso %d ---\n", step);
		printf("Stack A: Stack B:\n");
		printf("------- -------\n");
		while (iteri_a || iteri_b)
		{
			if (iteri_a)
			{
				printf("%-11d", iteri_a->content);
				iteri_a = iteri_a->next;
			}
			else
				printf("           "); // Espacios para alinear
			if (iteri_b)
			{
				printf("%d\n", iteri_b->content);
				iteri_b = iteri_b->next;
			}
			else
				printf("\n");
		}
		printf("---------------------\n");
		// --- FIN DE IMPRESIÓN ---

		printf("Introduce un movimiento (sa, pb, rra, ...): ");

		if (fgets(comando, sizeof(comando), stdin) == NULL)
		{
			printf("Fin de la entrada.\n");
			break;
		}

		comando[strcspn(comando, "\n")] = '\0';

		int movimiento_valido = 1;

		if (strcmp(comando, "sa") == 0)
			ft_sa(&stack_a);
		else if (strcmp(comando, "sb") == 0)
			ft_sb(&stack_b);
		else if (strcmp(comando, "ss") == 0)
			ft_ss(&stack_a, &stack_b);
		// Corregido: ft_pa(destino_A, origen_B)
		else if (strcmp(comando, "pa") == 0)
			ft_pa(&stack_a, &stack_b);
		else if (strcmp(comando, "pb") == 0)
			ft_pb(&stack_a, &stack_b);
		else if (strcmp(comando, "ra") == 0)
			ft_ra(&stack_a);
		else if (strcmp(comando, "rb") == 0)
			ft_rb(&stack_b);
		else if (strcmp(comando, "rr") == 0)
			ft_rr(&stack_a, &stack_b);
		// --- Movimientos añadidos ---
		else if (strcmp(comando, "rra") == 0)
			ft_rra(&stack_a);
		else if (strcmp(comando, "rrb") == 0)
			ft_rrb(&stack_b);
		else if (strcmp(comando, "rrr") == 0)
			ft_rrr(&stack_a, &stack_b);
		else
		{
			printf("Error: Movimiento '%s' no reconocido.\n", comando);
			movimiento_valido = 0;
			// Pequeña pausa para que el usuario vea el error
			// (Opcional, requiere <unistd.h>)
			// sleep(1); 
		}

		if (movimiento_valido)
			step++;
	}

	system("clear"); // Limpiar la pantalla una última vez
	iteri_a = stack_a;
	iteri_b = stack_b;
	printf("\n--- Paso %d ---\n", step);
		printf("Stack A: Stack B:\n");
		printf("------- -------\n");
		while (iteri_a || iteri_b)
		{
			if (iteri_a)
			{
				printf("%-11d", iteri_a->content);
				iteri_a = iteri_a->next;
			}
			else
				printf("           "); // Espacios para alinear
			if (iteri_b)
			{
				printf("%d\n", iteri_b->content);
				iteri_b = iteri_b->next;
			}
			else
				printf("\n");
		}
		printf("---------------------\n");
	printf("Game passed on %d steps!\n", step);

	// Liberar memoria
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(int_arr);
	return (0);
}