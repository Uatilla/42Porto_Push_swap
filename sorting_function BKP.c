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
	//printf("sa\n");
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

void	setting_tail_and_head(t_stack **dest, t_stack *old_head)
{
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
}

static void	do_push(t_stack **src, t_stack **dest)
{
	t_stack	*new_head_src;
	t_stack	*tail;
	t_stack	*old_head;

	if (*src == NULL)
		return ;
	old_head = *src;
	new_head_src = old_head->next;
	tail = old_head->prev;
	tail->next = new_head_src;
	new_head_src->prev = tail;
	//Setting the prev of the dest.
	setting_tail_and_head(dest, old_head);
	/*If the source has only one element, the stack_source need to be NULL after do push operation*/
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

void	do_operations(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	do_op_rotate(stack_a, stack_b, temp);
	do_op_rev_rotate(stack_a, stack_b, temp);
	do_pb(&*stack_a, &*stack_b);
}
