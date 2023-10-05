/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:49:07 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/05 20:49:09 by uviana-a         ###   ########.fr       */
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
