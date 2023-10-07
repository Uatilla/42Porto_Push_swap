/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_pos_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:46:46 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/07 14:46:47 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos_cost3(t_stack *temp_a, t_stack *temp_b, int size_b)
{
	int	j;

	j = 0;
	while (j < size_b)
	{
		if (temp_a->index > temp_b->index 
			&& temp_a->index < temp_b->prev->index)
		{
			temp_a->rb = temp_b->ra;
			temp_a->rrb = temp_b->rra;
		}
		temp_b = temp_b->next;
		j++;
	}
}

void	set_pos_cost2(t_stack *temp_a, t_stack *temp_b, int size_a, int size_b)
{
	int	trigger;
	int	i;
	int	lowest_index;
	int	highest_index;

	highest_index = ft_find_index(&temp_b, 'H');
	lowest_index = ft_find_index(&temp_b, 'L');
	trigger = 1;
	i = 0;
	while (trigger == 1 || i < size_a)
	{
		trigger = 0;
		if (temp_a->index > highest_index || temp_a->index < lowest_index)
		{
			temp_a->rb = temp_b->ra;
			temp_a->rrb = temp_b->rra;
		}
		else
			set_pos_cost3(temp_a, temp_b, size_b);
		temp_a = temp_a->next;
		i++;
	}
}

void	set_pos_cost(t_stack **src, t_stack **dest, int size_a, int size_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *src;
	temp_b = *dest;
	while (temp_b->index != ft_find_index(dest, 'H'))
		temp_b = temp_b->next;
	set_pos_cost2(temp_a, temp_b, size_a, size_b);
}
