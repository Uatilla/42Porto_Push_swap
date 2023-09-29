/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_costs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:48:02 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/28 19:48:04 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_total_cost(t_stack **stack_a)
{
	int	size_a;
	int	i;
	t_stack	*temp;

	i = 0;
	size_a = ft_size_stack(*stack_a);
	temp = *stack_a;
	while (i < size_a)
	{
		temp->total = temp->ra + temp->rb + temp->rr + temp->rra + temp->rrb + temp->rrr;
		temp = temp->next;
		i++;
	}
}

void	setting_position_costs(t_stack **src, t_stack **dest, int size_a, int size_b)
{
	int	trigger;
	int	highest_index;
	int	lowest_index;
	t_stack *temp_a;
	t_stack	*temp_b;
	int	i;
	int	j;

	highest_index = ft_find_index(dest, 'H');
	lowest_index = ft_find_index(dest, 'L');
	temp_a = *src;
	temp_b = *dest;
	while (temp_b->index != highest_index)
		temp_b = temp_b->next;
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
		{
			j = 0;
			while (j < size_b)
			{
				if (temp_a->index > temp_b->index && temp_a->index < temp_b->prev->index)
				{
					temp_a->rb = temp_b->ra;
					temp_a->rrb = temp_b->rra;
				}
				temp_b = temp_b->next;
				j++;
			}
		}
			
		temp_a = temp_a->next;
		i++;
	}
}

void	setting_costs(t_stack **stack, int size)
{
	t_stack	*temp;

	temp = *stack;
	if (size % 2 == 0)
	{
		while (temp->pos <= size/2)
		{
			temp->ra = temp->pos - 1;
			temp->rra = 0;
			temp = temp->next;
		}
		while (temp->pos > size/2)
		{
			temp->rra = size - temp->pos + 1;
			temp->ra = 0;
			temp = temp->next;
		}
	}
	else
	{
		while (temp->pos <= (size/2) + 1)
		{
			temp->ra = temp->pos - 1;
			temp->rra = 0;
			temp = temp->next;
		}
		while (temp->pos > (size/2) + 1)
		{
			temp->rra = size - temp->pos + 1;
			temp->ra = 0;
			temp = temp->next;
		}
	}
}

void	setting_current_pos(t_stack **stack)
{
	t_stack	*head;
	int	trigger;
	int	i;

	head = *stack;
	trigger = 1;
	i = 0;
	while (++i && (head != *stack || trigger == 1))
	{
		trigger = 0;
		head->pos = i;
		head = head->next;
	}
}

void	ft_id_best_cost(t_stack **stack)
{
	t_stack	*temp_a;
	int	size_a;
	int	i;

	temp_a = *stack;
	size_a = ft_size_stack(*stack);
	i = 0;
	while (i < size_a)
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
		temp_a = temp_a->next;
		i++;
	}
}

t_stack	*ft_lowest_cost(t_stack **stack_a)
{
	int	i;
	int	j;
	int	trigger;
	t_stack	*temp;
	int	size_a;

	temp = *stack_a;
	
	i = -1;
	size_a = ft_size_stack(*stack_a);
	j = 0;
	while (temp->total != i)
	{
		i++;
		trigger = 1;
		while (temp->total != i && (trigger == 1 || temp != *stack_a))
		{
			trigger = 0;
			temp = temp->next;
		}
			if (temp->total == i)
				return (temp);
	}
	return (0);
}