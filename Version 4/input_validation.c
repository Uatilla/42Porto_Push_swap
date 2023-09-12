/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:36:41 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/08 19:44:44 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_checker_input(char **arg_List)
{
	int	i;

	i = 0;
	while (arg_List[++i])
	{
		/*2.1) Check if the argument is only made of numbers.*/
		if (!ft_isanumber(arg_List[i]))
			return (0);
	}
	return (1);
}

int	ft_is_sign(char first_Char)
{
	if (first_Char == '-' || first_Char == '+')
		return (1);
	return (0);
}

int	ft_isdigit(int arg_Char)
{
	return (arg_Char >= '0' && arg_Char <= '9');
}

/*if I change the inside whiled to while (arg_String[++i]) e should 
change the second while to remove it's i++ too.*/
int	ft_isanumber(char *arg_String)
{
	int	i;

	i = 0;
	while (arg_String[i])
	{
		if (ft_is_sign(arg_String[i]) && arg_String[i + 1] != '\0')
			i++;
		while (arg_String[i] && ft_isdigit(arg_String[i]))
			i++;
		if (arg_String[i] != '\0')
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	number;

	signal = 1;
	number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signal = signal * (-1);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number *= 10;
		number += *nptr - 48;
		nptr++;
	}
	return (signal * number);
}

//I can put the right index here. just need to add a condition to run the
//while until all index were done (incrementing i until argc).
int	ft_linking_nodes(char **argv, t_stack *stack_push)
{
	int	i;
	t_stack *new_node;
    t_stack	*linking_nodes;


	i = 0;
    while (argv[++i])
	{
		//3.1) Allocating the first value on the head of the struct.
		if (i == 1)
		{
			stack_push->value = ft_atoi(argv[i]);
			stack_push->index = 0;
			stack_push->next = NULL;
			stack_push->prev = NULL;
		}
		else
		{
			//3.2) Creating a new node.
			new_node = malloc(sizeof(t_stack));
			if (!new_node)
				return (0);
			else
			{
				new_node->value = ft_atoi(argv[i]);
				new_node->index = 0;
				new_node->next = NULL;
				//3.3) Linking prev and next of the node created with a pointer.
				linking_nodes = stack_push;
				while (linking_nodes->next != NULL)
					linking_nodes = linking_nodes->next;
				linking_nodes->next = new_node;
				new_node->prev = linking_nodes;
			}
		}
	}
	//3.4) Linking the head and tail to make a double circle linked list.
	if (new_node)
	{
		new_node->next = stack_push;
		stack_push->prev = new_node;
	}
    return (1);
}



int	ft_check_nodes_duplicated(t_stack *stack_push)
{
	t_stack *node_a;
	t_stack *node_b;
	int	trigger;

	node_a = stack_push;
	trigger = 1;
	/*4.1) stack_push is the head, so the checking of duplicated 
	numbers should run only until stack_push position.*/
	while (node_a != stack_push || trigger == 1)
	{
		trigger = 0;
		node_b = node_a->next;
		while(node_b != stack_push)
		{
			if (node_a->value == node_b->value)
				return (0);
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}

	return (1);
}

void	ft_set_index(int argc, t_stack *stack_push)
{
	t_stack *check_index;
	t_stack *highest_node;
	int	current_highest;
	int	trigger;

	if (argc == 2)
	{
		stack_push->index = 1;
		return ;
	}
	while (--argc > 0)
	{
		/*5.1) Reseting all conference values to verify the next highest number.*/
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