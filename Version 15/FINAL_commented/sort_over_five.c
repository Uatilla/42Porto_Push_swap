/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:33:10 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/07 14:33:11 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
