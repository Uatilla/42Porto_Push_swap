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
