/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:56:11 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/18 23:40:15 by edu-legion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************************************************************/
/*																			  */
/*                                 EXTERN LIBS                                */
/*  																		  */
/******************************************************************************/
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h> //pdte quitar
/******************************************************************************/
/* 																			  */
/* 									 MACROS                                   */
/* 																		 	  */
/******************************************************************************/

/******************************************************************************/
/* 																			  */
/* 									VARIABLES                                 */
/* 																			  */
/******************************************************************************/

/******************************************************************************/
/* 																			  */
/* 									 STRUCTS                                  */
/* 																			  */
/******************************************************************************/
typedef struct s_stack
{
	int				content;
	int				index;
	int				target;
	int				topcost;
	int				targetcost;
	struct s_stack	*next;
}	t_stack;

/******************************************************************************/
/* 																			  */
/* 									FUNCTIONS                                 */
/* 																			  */
/******************************************************************************/
// --- libft functions ---
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_atoi(const char *nptr, char **matrix);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
// --- Free and exit ---
void	free_and_exit(int error, char **matrix, int *int_arr);
// --- Validate and parse Utils ---
int		*atoi_args(int size, char **matrix);
void	check_chars(char *str, char *limit, char **matrix);
// --- Validate and Parse ---
int		*validate_and_parse(int argc, char **argv, int *size);
// --- Push ---
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
// --- Swap ---
void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
// --- Rotate ---
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **stack_1, t_stack **stack_2);
// --- Reverse rotate ---
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **stack_1, t_stack **stack_2);
// --- Sort 3---
void	sort_3_a(t_stack **stack);
void	sort_3_b(t_stack **stack);
// --- Lists aux functions ---
int	ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int content);
int		ft_node_position(t_stack *stack, t_stack *node);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
#endif
