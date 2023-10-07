/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rev_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:01:25 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/07 15:01:26 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_rotate(t_stack **src)
{
	if (*src == NULL)
		return ;
	*src = (*src)->prev;
}

void	do_rra(t_stack	**stack_a)
{
	do_rev_rotate(&*stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_stack	**stack_b)
{
	do_rev_rotate(&*stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_stack	**stack_a, t_stack **stack_b)
{
	do_rev_rotate(&*stack_a);
	do_rev_rotate(&*stack_b);
	ft_putstr_fd("rrr\n", 1);
}

void	do_op_rev_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
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
