/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_turk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:26:58 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/19 09:40:33 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_addtarget(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*iteri_a;
	t_stack	*iteri_b;

	iteri_b = *stack_b;
	while (iteri_b->next)
	{
		iteri_a = *stack_a;
		while (iteri_b->index > iteri_a->index && iteri_b->next)
			iteri_a = iteri_a->next;
		if (iteri_b->index < iteri_a->index)
			iteri_b->target = iteri_a->index;
		if (iteri_b->index > iteri_a->index && !iteri_a->next)
			iteri_b->target = *stack_a->index;
	}
}

void	ft_totopcost(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		topcost;
	t_stack	*iteri;

	iteri = *stack_b;
	i = 0;
	while (iteri)
	{
		if (ft_node_position(iteri) <= ft_lstsize(*stack_b) / 2)
			iteri->topcost = i;
		else
			iteri->topcost = ft_lstsize(*stack_b) - i;
		iteri = iteri->next;
		i++;
	}
}

void	ft_totargetcost(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	iteri_b = *stack_b;
	while (iteri_b)
	{
		i = 0;
		iteri_a = *stack_a;
		while (iteri_a)
		{
			if (iteri_b->target == iteri_a->index)
			{
				if (ft_node_position(iteri_a) <= ft_lstsize(*stack_a) / 2)
					iteri_b->targetcost = i;
				else
					iteri_b->targetcost = ft_lstsize(*stack_a) - i;
			}
			else
				iteri_a = iteri_a->next;
			i++;
		}
		iteri_b = iteri_b->next;
	}
}

void	ft_turk(t_stack **stack_a, t_stack_b, size)
{
	int		i;
	t_stack *iteri_a;
	t_stack *iteri_b;
	t_stack	*mincost;

	i = 0;
	while (i++ < size - 3)
		ft_pb(stack_a, stack_b);
	sort_3_a(stack_a);
	ft_addtarget(stack_a, stack_b);
	i = 0;
	while (i++ < size - 3)
	{
		ft_totopcost(stack_a, stack_b);
		ft_totargetcost(stack_a, stack_b);
		iteri_a = *stack_a;
		iteri_b = *stack_b;
		mincost = stack_b;
		while (iteri_b)
		{
			if (iteri->topcost + iteri->targetcost < min->topcost + min->targetcost)
				min = iteri;
			else
				iteri_b = iteri_b->next;
		}
		stack_manager(stack_a, stack_b);
	}
}
