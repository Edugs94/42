/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:36:40 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/14 14:49:30 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	checker(t_stack *stack, int size)
{
	t_stack	*iteri;
	int		i;

	iteri = stack;
	i = 0;
	while(iteri->next)
	{
		if (iteri->content < iteri->next->content)
		{
			iteri = iteri->next;
			i++;
		}
		else
			return (-1);
	}
	if (i != size)
		return (-2);
	return (0);
}

int	main(int argc, char **argv)
{
	int		*int_arr;
	int		step;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*iteri_a;
	t_stack	*iteri_b;

	step = 0;
	if (argc <= 2)a
	{
		printf("Write at least 2 numbers\n");
		return (-1);
	}
	int_arr = atoi_args(argc, argv);
	stack_a = create_stack(argc, int_arr);
	add_index(stack_a, argc -1);
	stack_b = NULL;
	while (checker(stack_a, argc - 1) != 0)
    {
        iteri_a = stack_a;
        iteri_b = stack_b;

        // --- IMPRESIÓN CORREGIDA (PARA EVITAR CRASH) ---
        printf("\n--- Paso %d ---\n", step);
        printf("Stack A:    Stack B:\n");
        printf("-------     -------\n");
        while (iteri_a || iteri_b)
        {
            if (iteri_a)
            {
                printf("%-11d", iteri_a->content); // Imprime A
                iteri_a = iteri_a->next;
            }
            else
                printf("           "); // Espacio si A está vacío

            if (iteri_b)
            {
                printf("%d\n", iteri_b->content); // Imprime B y salto de línea
                iteri_b = iteri_b->next;
            }
            else
                printf("\n"); // Solo salto de línea si B está vacío
        }
        printf("---------------------\n");
        // --- FIN DE IMPRESIÓN ---


        //
        // --- AQUI PEDIR RESPUESTA POR PANTALLA ---
        //
        printf("Introduce un movimiento (sa, pb, rra, ...): ");
        
        // 1. Leer el comando del usuario (PAUSA EL PROGRAMA)
        if (fgets(comando, sizeof(comando), stdin) == NULL)
        {
            // Si hay un error o el usuario pulsa Ctrl+D (EOF)
            printf("Fin de la entrada.\n");
            break; 
        }

        // 2. Limpiar el '\n' (Enter) que fgets() guarda
        comando[strcspn(comando, "\n")] = '\0';

        // 3. Comprobar el comando y ejecutar la función
        int movimiento_valido = 1; // Flag para contar el paso

        if (strcmp(comando, "sa") == 0)
            ft_sa(&stack_a);
        else if (strcmp(comando, "sb") == 0)
            ft_sb(&stack_b);
        else if (strcmp(comando, "ss") == 0)
            ft_ss(&stack_a, &stack_b);
        else if (strcmp(comando, "pa") == 0)
            ft_pa(&stack_b, &stack_a);
        else if (strcmp(comando, "pb") == 0)
            ft_pb(&stack_a, &stack_b);
        else if (strcmp(comando, "ra") == 0)
            ft_ra(&stack_a);
        else if (strcmp(comando, "rb") == 0)
            ft_rb(&stack_b);
        else if (strcmp(comando, "rr") == 0)
            ft_rr(&stack_a, &stack_b);
        // ...
        // ... (Añade 'else if' para TODOS tus 11 movimientos: sb, ss, pa, ra, rb, rr, rrb, rrr)
        // ...
        else
        {
            printf("Error: Movimiento '%s' no reconocido.\n", comando);
            movimiento_valido = 0; // No contamos esto como un paso
        }

        // 4. Incrementar el contador si el movimiento fue válido
        if (movimiento_valido)
            step++;
        
        //
        // --- TRAS ESTO, VOLVER AL PRINCIPIO DEL BUCLE ---
        //
    }

    printf("\n¡Ejercicio completado!\n");
    printf("Cantidad total de pasos: %d\n", step);
    
    // (Recuerda liberar la memoria de los stacks)
    free_stack(&stack_a);
    free_stack(&stack_b);
    free(int_arr);
    return 0;
}
