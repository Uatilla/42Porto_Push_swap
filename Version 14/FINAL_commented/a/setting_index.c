/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:40:19 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/07 14:40:21 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_set_index(int argc, t_stack *stack_push)
{
	t_stack	*check_index;
	t_stack	*highest_node;
	int		current_highest;
	int		trigger;

	if (argc == 2)
	{
		stack_push->index = 1;
		return ;
	}
	while (--argc > 0)
	{
		//5.1) Reseting all conference values 
		//to verify the next highest number.
		check_index = stack_push;
		current_highest = INT_MIN;
		highest_node = NULL;
		trigger = 1;
		while (check_index != stack_push || trigger == 1)
		{
			trigger = 0;
			if (check_index->value == INT_MIN && check_index->index == 0)
				check_index->index = 1;
			if (check_index->value > current_highest && check_index->index == 0)
			{
				current_highest = check_index->value;
				highest_node = check_index;
			}
			check_index = check_index->next;
		}
		if (highest_node != NULL)
			highest_node->index = argc;
	}
}*/

void	setting_index(t_stack *stack_push, t_stack *highest_node, int argc)
{
	t_stack	*check_index;
	int		current_highest;
	int		trigger;

	check_index = stack_push;
	current_highest = INT_MIN;
	trigger = 1;
	while (check_index != stack_push || trigger == 1)
	{
		trigger = 0;
		if (check_index->value == INT_MIN && check_index->index == 0)
			check_index->index = 1;
		if (check_index->value > current_highest && check_index->index == 0)
		{
			current_highest = check_index->value;
			highest_node = check_index;
		}
		check_index = check_index->next;
	}
	if (highest_node != NULL)
		highest_node->index = argc;
}

void	ft_set_index(int argc, t_stack *stack_push)
{
	t_stack	*highest_node;

	if (argc == 2)
	{
		stack_push->index = 1;
		return ;
	}
	while (--argc > 0)
	{
		//5.1) Reseting all conference values 
		//to verify the next highest number.
		highest_node = NULL;
		setting_index(stack_push, highest_node, argc);
	}
}
