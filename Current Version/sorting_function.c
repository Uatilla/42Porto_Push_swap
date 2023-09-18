/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:24:13 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/12 08:57:10 by uatilla          ###   ########.fr       */
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

/*static void	do_push(t_stack **src, t_stack **dest)
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
	if ((*src)->next == *src)
		*dest = NULL;
	else
		*dest = *src;
	*src = new_head_src;
}*/

static void	do_push(t_stack **src, t_stack **dest)
{
	t_stack *new_head_src;
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

int	ft_find_highest_index(t_stack **stack)
{
	t_stack *temp;
	int	highest_index;
	int	trigger;

	temp = *stack;
	trigger = 1;
	if (!temp)
		return (0);
	while (temp && (temp != *stack || trigger == 1))
	{
		trigger = 0;
		if (temp == *stack)
			highest_index = temp->index;
		else if (highest_index < temp->index)
		{
			highest_index = temp->index;
		}
		temp = temp->next;

	}
	//printf("Highest Index: %d\n",highest_index);
	return (highest_index);
}

void	sort_three(t_stack **stack)
{
	int	highest_index;

	highest_index = ft_find_highest_index(stack);
	if (ft_is_sorted(*stack))
		return ;
	if ((*stack)->index == highest_index)
		do_ra(stack);
	else if ((*stack)->next->index == highest_index)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_sorted(*stack_a))
		return ;
	if ((*stack_a)->index == 1)
		do_pb(stack_a, stack_b);
	else if ((*stack_a)->prev->index == 1)
		do_rra(stack_a);
	else
		while ((*stack_a)->index != 1)
			do_ra(stack_a);
	do_pb(stack_a, stack_b);
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
}