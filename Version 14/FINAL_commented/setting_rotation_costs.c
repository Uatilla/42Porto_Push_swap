/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_rotation_costs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:48:47 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/07 14:48:48 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_id_best_rotate_cost(t_stack *temp_a)
{
	if (temp_a->ra != 0 && temp_a->rb != 0)
	{
		if (temp_a->ra > temp_a->rb)
		{
			temp_a->rr = temp_a->rb;
			temp_a->ra = temp_a->ra - temp_a->rb;
			temp_a->rb = 0;
		}
		else
		{
			temp_a->rr = temp_a->ra;
			temp_a->rb = temp_a->rb - temp_a->ra;
			temp_a->ra = 0;
		}
	}
	else
		temp_a->rr = 0;
}

void	ft_id_best_rev_rotate_cost(t_stack *temp_a)
{
	if (temp_a->rra != 0 && temp_a->rrb != 0)
	{
		if (temp_a->rra > temp_a->rrb)
		{
			temp_a->rrr = temp_a->rrb;
			temp_a->rra = temp_a->rra - temp_a->rrb;
			temp_a->rrb = 0;
		}
		else
		{
			temp_a->rrr = temp_a->rra;
			temp_a->rrb = temp_a->rrb - temp_a->rra;
			temp_a->rra = 0;
		}
	}
	else
		temp_a->rrr = 0;
}

void	ft_id_best_cost(t_stack **stack)
{
	t_stack	*temp_a;
	int		size_a;
	int		i;

	temp_a = *stack;
	size_a = ft_size_stack(*stack);
	i = 0;
	while (i < size_a)
	{
		ft_id_best_rotate_cost(temp_a);
		ft_id_best_rev_rotate_cost(temp_a);
		temp_a = temp_a->next;
		i++;
	}
}
