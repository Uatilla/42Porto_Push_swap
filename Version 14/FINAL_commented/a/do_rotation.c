/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:57:29 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/07 14:57:30 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_stack **src)
{
	if (*src == NULL)
		return ;
	*src = (*src)->next;
}

void	do_ra(t_stack **stack_a)
{
	do_rotate(&*stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	do_rb(t_stack **stack_b)
{
	do_rotate(&*stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_rotate(&*stack_a);
	do_rotate(&*stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	do_op_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
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
