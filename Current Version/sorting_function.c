/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:24:13 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/07 19:24:15 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_push)
{
	t_stack	*temp;

	if (stack_push->next == NULL)
	{
		printf("Only one node! It's already sorted!\n");
		return (1);
	}
	temp = stack_push;
	while (temp->next != stack_push)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;	
	}
	return (1);

}

static void	do_swap(t_stack **stack_push)
{
	t_stack	*tail;
	t_stack *old_head;
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
}

void	do_sb(t_stack **stack_b)
{
	do_swap(&*stack_b);
}

static void	do_push(t_stack **src, t_stack **dest)
{
	t_stack *new_head_src;

	if (*src == NULL)
		return ;
	new_head_src = (*src)->next;
	(*src)->prev->next = new_head_src;
	new_head_src->prev = (*src)->prev;
	(*src)->next = *dest;
	//Setting the prev of the dest.
	if (*dest == NULL)
	{
		(*src)->prev = (*src);
		(*src)->next = (*src);
	}
	else
		(*src)->prev = (*dest)->prev;
	*dest = *src;
	*src = new_head_src;
}

void	do_pa(t_stack **stack_b, t_stack **stack_a)
{
	do_push(&*stack_b, &*stack_a);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	do_push(&*stack_a, &*stack_b);
}

static void	do_rotate(t_stack **src)
{
	if (*src == NULL)
		return ;
	*src = (*src)->next;

}

void	do_ra(t_stack **stack_a)
{
	do_rotate(&*stack_a);
}

static void	do_rev_rotate(t_stack **src)
{
	if (*src == NULL)
		return ;
	*src = (*src)->prev;
}

void	do_rra(t_stack	**stack_a)
{
	do_rev_rotate(&*stack_a);
}