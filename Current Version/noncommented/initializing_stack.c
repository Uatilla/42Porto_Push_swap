/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:16:28 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/01 18:16:29 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	starting_new_node(t_stack *stack_push, char *argv)
{
	stack_push->value = (int)ft_atoi(argv);
	stack_push->index = 0;
	stack_push->next = NULL;
	stack_push->prev = NULL;
}

t_stack	*create_new_node(char *value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	starting_new_node(new_node, value);
	return (new_node);
}

void	link_nodes(t_stack *stack_push, t_stack *new_node)
{
	t_stack	*linking_nodes;

	linking_nodes = stack_push;
	while (linking_nodes->next != NULL)
		linking_nodes = linking_nodes->next;
	linking_nodes->next = new_node;
	new_node->prev = linking_nodes;
}

int	ft_linking_nodes(char **argv, t_stack *stack_push)
{
	int		i;
	t_stack	*new_node;

	i = 0;
	while (argv[++i])
	{
		if (i == 1)
			starting_new_node(stack_push, argv[i]);
		else
		{
			new_node = create_new_node(argv[i]);
			if (!new_node)
				return (0);
			link_nodes(stack_push, new_node);
		}
	}
	if (new_node)
	{
		new_node->next = stack_push;
		stack_push->prev = new_node;
	}
	return (1);
}

int	ft_check_nodes_duplicated(t_stack *stack_push)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		trigger;

	node_a = stack_push;
	trigger = 1;
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

void	ft_set_index(int argc, t_stack *stack_push)
{
	t_stack	*check_index;
	t_stack	*highest_node;
	int		current_highest;
	int		trigger;

	if (argc == 2)
	{
		stack_push->index = 1;
		return ;
	}
	while (--argc > 0)
	{
		check_index = stack_push;
		current_highest = INT_MIN;
		highest_node = NULL;
		trigger = 1;
		while (check_index != stack_push || trigger == 1)
		{
			trigger = 0;
			if (check_index->value == INT_MIN && check_index->index == 0)
				check_index->index = 1;
			if (check_index->value > current_highest && check_index->index == 0)
			{
				current_highest = check_index->value;
				highest_node = check_index;
			}
			check_index = check_index->next;
		}
		if (highest_node != NULL)
			highest_node->index = argc;
	}
}
