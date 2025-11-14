/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* node_creator.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/11/13 11:23:54 by egalindo          #+#    #+#             */
/* Updated: 2025/11/14 17:00:00 by Gemini          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

// --- Funciones auxiliares añadidas ---

// Una implementación simple de ft_atoi
long	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

// --- Tus funciones (corregidas) ---

int	*atoi_args(int argc, char **argv)
{
	int		*arr;
	int		i;

	i = 0;
	// ¡¡CRÍTICO: Reservar memoria para el array!!
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (arr == NULL)
		return (NULL);
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->index = 0; // Importante para add_index
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*iter;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	iter = *lst;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = new;
}

// Lógica de add_index corregida
void	add_index(t_stack **stack, int size)
{
	int		i;
	long	last;
	t_stack	*min;
	t_stack	*iteri;

	i = 0;
	if (!stack || !*stack || size <= 0)
		return ;
	last = LONG_MIN;
	while (i < size)
	{
		iteri = *stack;
		min = NULL; // Resetear min en cada iteración

		// 1. Encontrar el primer candidato (uno que no tenga índice)
		while (iteri)
		{
			if (iteri->content > last && iteri->index == 0)
			{
				min = iteri;
				break;
			}
			iteri = iteri->next;
		}

		// 2. Encontrar el mínimo real
		iteri = *stack;
		while (iteri)
		{
			// Si encontramos uno más pequeño que 'min' (y que no tenga índice)
			if (iteri->content > last && iteri->content < min->content 
				&& iteri->index == 0)
				min = iteri;
			iteri = iteri->next;
		}

		if (min) // Si encontramos un mínimo
		{
			min->index = i;
			last = min->content;
		}
		i++;
	}
}

// Corregido: Renombrado a 'create_stack' y usa 'int_arr'
t_stack	*create_stack(int size, int *int_arr)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	if (size <= 0 || !int_arr)
		return (NULL);
	i = 0;
	// ¡CORREGIDO! No se usa ft_atoi, ya es un int
	stack = ft_lstnew(int_arr[i]);
	i++;
	while (i < size)
	{
		// ¡CORREGIDO!
		new_node = ft_lstnew(int_arr[i]);
		if (!new_node)
		{
			free_stack(&stack); // Liberar lo creado si falla
			return (NULL);
		}
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}