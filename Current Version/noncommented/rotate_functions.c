/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:40:49 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/05 20:40:50 by uviana-a         ###   ########.fr       */
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
