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

void	do_operations(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	do_op_rotate(stack_a, stack_b, temp);
	do_op_rev_rotate(stack_a, stack_b, temp);
	do_pb(&*stack_a, &*stack_b);
}
