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

void	identifying_costs(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	int	size_b;

	setting_current_pos(stack_a);
	setting_current_pos(stack_b);
	size_a = ft_size_stack(*stack_a);
	size_b = ft_size_stack(*stack_b);
	setting_costs_even(stack_a, size_a);
	setting_costs_even(stack_b, size_b);
	set_pos_cost(stack_a, stack_b, size_a, size_b);
	ft_id_best_cost(stack_a);
	set_total_cost(stack_a);
}

void	ordering_stack_b(t_stack **stack_b)
{
	int		size_b;
	int		highest_index;
	t_stack	*temp;

	setting_current_pos(stack_b);
	size_b = ft_size_stack(*stack_b);
	temp = *stack_b;
	highest_index = ft_find_index(stack_b, 'H');
	while (temp->index != highest_index)
		temp = temp->next;
	while ((*stack_b) != temp)
	{
		if (temp->pos <= size_b / 2)
			do_rb(stack_b);
		else
			do_rrb(stack_b);
	}
}

t_stack	*filling_stack_a(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	int	highest_index;

	highest_index = ft_find_index(stack_a, 'H');
	if ((*stack_b)->index > temp->index)
		do_pa(stack_b, stack_a);
	else if ((*stack_b)->index < temp->index 
		&& temp->index != highest_index)
	{
		do_rra(stack_a);
		temp = temp->prev;
	}
	else if (highest_index == temp->index && ft_size_stack(*stack_a) == 3)
	{
		do_rra(stack_a);
		temp = temp->prev;
	}
	else
		do_pa(stack_b, stack_a);
	return (&*temp);
}

void	returning_values(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a)->prev;
	while ((*stack_b) != NULL)
		temp = filling_stack_a(stack_a, stack_b, temp);
	while (temp->index < (*stack_a)->index)
	{
		do_rra(stack_a);
		temp = temp->prev;
	}
}

void	sort_over_five(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	t_stack	*temp;

	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
	size_a = ft_size_stack(*stack_a);
	while (size_a >= 4)
	{
		identifying_costs(stack_a, stack_b, size_a);
		temp = ft_lowest_cost(stack_a);
		do_operations(stack_a, stack_b, temp);
		size_a = ft_size_stack(*stack_a);
	}
	sort_three(stack_a);
	//Organizing stack_b (max to min)
	ordering_stack_b(stack_b);
	//Sending values from stack_b to stack_a
	//printf("=================sending==================\n");
	//printf("Temp_index: [%d]\n", temp->index);
	returning_values(stack_b, stack_a);
}
