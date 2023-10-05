/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:24:13 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/18 21:21:06 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_push)
{
	t_stack	*temp;

	if (stack_push->next == NULL)
		return (1);
	temp = stack_push;
	while (temp->next != stack_push)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	do_rotation(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->ra > 0)
	{
		do_ra(&*stack_a);
		temp->ra--;
	}
	while (temp->rb > 0)
	{
		do_rb(&*stack_b);
		temp->rb--;
	}
	while (temp->rr > 0)
	{
		do_rr(&*stack_a, &*stack_b);
		temp->rr--;
	}
}

void	do_rev_rotation(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->rra > 0)
	{
		do_rra(&*stack_a);
		temp->rra--;
	}
	while (temp->rrb > 0)
	{
		do_rrb(&*stack_b);
		temp->rrb--;
	}
	while (temp->rrr > 0)
	{
		do_rrr(&*stack_a, &*stack_b);
		temp->rrr--;
	}
}

void	do_operations(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	do_rotation(stack_a, stack_b, temp);
	do_rev_rotation(stack_a, stack_b, temp);
	do_pb(&*stack_a, &*stack_b);
}
