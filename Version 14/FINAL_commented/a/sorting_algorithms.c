/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:52:20 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/28 19:52:21 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	highest_index;

	highest_index = ft_find_index(stack, 'H');
	if (ft_is_sorted(*stack))
		return ;
	if ((*stack)->index == highest_index)
		do_ra(stack);
	else if ((*stack)->next->index == highest_index)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_sorted(*stack_a))
		return ;
	while ((*stack_a)->index != 1)
		do_ra(stack_a);
	do_pb(stack_a, stack_b);
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
}

int	mov_smallest_idx(t_stack **stack_a, t_stack **stack_b, int idx_to_move)
{
	if ((*stack_a)->index == idx_to_move)
	{
		do_pb(stack_a, stack_b);
		idx_to_move = 2;
	}
	else if ((*stack_a)->prev->index == idx_to_move)
	{
		do_rra(stack_a);
		idx_to_move = 1;
	}
	else if ((*stack_a)->prev->prev->index == idx_to_move)
	{
		do_rra(stack_a);
		do_rra(stack_a);
		idx_to_move = 1;
	}
	return (idx_to_move);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	idx_to_move;

	idx_to_move = 1;
	if (ft_is_sorted(*stack_a))
		return ;
	idx_to_move = mov_smallest_idx(stack_a, stack_b, idx_to_move);
	while (idx_to_move <= 2)
	{
		while ((*stack_a)->index != idx_to_move)
			do_ra(stack_a);
		do_pb(stack_a, stack_b);
		idx_to_move++;
	}
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
	do_pa(stack_b, stack_a);
}
