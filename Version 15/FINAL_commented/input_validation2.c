/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:38:18 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/07 14:38:20 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_nodes_duplicated(t_stack *stack_push)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		trigger;

	node_a = stack_push;
	trigger = 1;
	/*4.1) stack_push is the head, so the checking 
	of duplicated 
	numbers should run only until stack_push position.*/
	while (node_a != stack_push || trigger == 1)
	{
		trigger = 0;
		node_b = node_a->next;
		while (node_b != stack_push)
		{
			if (node_a->value == node_b->value)
				return (0);
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}
	return (1);
}

int	check_extr_int(t_stack *stack_a)
{
	t_stack	*temp;
	int		trigger;

	trigger = 1;
	temp = stack_a;
	while (stack_a != temp || trigger == 1)
	{
		trigger = 0;
		if (temp->value > 2147483647 || temp->value < -2147483648)
			return (0);
		temp = temp->next;
	}
	return (1);
}
