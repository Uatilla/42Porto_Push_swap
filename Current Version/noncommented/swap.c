/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:38:06 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/05 20:38:08 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap(t_stack **stack_push)
{
	t_stack	*tail;
	t_stack	*old_head;
	t_stack	*new_head;

	if (!*stack_push)
		return ;
	if ((*stack_push)->next == NULL)
		return ;
	tail = (*stack_push)->prev;
	new_head = (*stack_push)->next;
	old_head = *stack_push;
	tail->next = new_head;
	new_head->next->prev = old_head;
	old_head->next = new_head->next;
	new_head->next = old_head;
	old_head->prev = new_head;
	new_head->prev = tail;
	*stack_push = new_head;
}

void	do_sa(t_stack **stack_a)
{
	do_swap(&*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_stack **stack_b)
{
	do_swap(&*stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_swap(&*stack_a);
	do_swap(&*stack_b);
	ft_putstr_fd("ss\n", 1);
}
