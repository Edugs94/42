/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:20:47 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/15 13:22:26 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************************************************************/
/*                                                                            */
/*                                 EXTERN LIBS                                */
/*                                                                            */
/******************************************************************************/

# include <unistd.h>
# include <stdlib.h> // Para malloc, free
# include <limits.h> // Para LONG_MIN
# include <stdio.h>  // Para printf, fgets
# include <string.h> // Para strcmp, strcspn

/******************************************************************************/
/*                                                                            */
/*                                   MACROS                                   */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                  VARIABLES                                 */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                   STRUCTS                                  */
/*                                                                            */
/******************************************************************************/

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_list
{
	t_stack		*s_a;
	t_stack		*s_b;
}	t_list;

/******************************************************************************/
/*                                                                            */
/*                                  FUNCTIONS                                 */
/*                                                                            */
/******************************************************************************/

//node_creator.c
int			*atoi_args(int argc, char **argv);
t_stack		*ft_lstnew(int content);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		add_index(t_stack **stack, int size);
t_stack		*create_stack(int size, int *int_arr);
void		free_stack(t_stack **stack);
long		ft_atoi(const char *str); // Añadida

//swap.c
void		ft_swap(t_stack **stack);
void		ft_sa(t_stack **stack);
void		ft_sb(t_stack **stack);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);

//push.c
void		ft_push(t_stack **stack_1, t_stack **stack_2);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);

//rotate.c
void		ft_rotate(t_stack **stack);
void		ft_ra(t_stack **stack);
void		ft_rb(t_stack **stack);
void		ft_rr(t_stack **stack_1, t_stack **stack_2);

//reverse_rotate.c
void		ft_rrotate(t_stack **stack);
void		ft_rra(t_stack **stack);
void		ft_rrb(t_stack **stack);
void		ft_rrr(t_stack **stack_1, t_stack **stack_2);

#endif
