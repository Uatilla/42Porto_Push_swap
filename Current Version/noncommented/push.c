/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:39:36 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/05 20:39:37 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upd_stk_point(t_stack **src, t_stack **tail, t_stack **new_head_src)
{
	t_stack	*old_head;

	old_head = *src;
	*new_head_src = old_head->next;
	*tail = old_head->prev;
	(*tail)->next = *new_head_src;
	(*new_head_src)->prev = *tail;
}

static void	do_push(t_stack **src, t_stack **dest)
{
	t_stack	*new_head_src;
	t_stack	*tail;
	t_stack	*old_head;

	old_head = NULL;
	if (*src == NULL)
		return ;
	upd_stk_point(src, &tail, &new_head_src);
	if (*dest == NULL)
	{
		old_head->prev = old_head;
		old_head->next = old_head;
	}
	else
	{
		old_head->next = *dest;
		old_head->prev = (*dest)->prev;
		(*dest)->prev->next = old_head;
		(*dest)->prev = old_head;
	}
	*dest = old_head;
	if (*src == tail)
		new_head_src = NULL;
	*src = new_head_src;
}

void	do_pa(t_stack **stack_b, t_stack **stack_a)
{
	do_push(&*stack_b, &*stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	do_push(&*stack_a, &*stack_b);
	ft_putstr_fd("pb\n", 1);
}
