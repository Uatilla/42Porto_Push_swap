/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:47:31 by uviana-a          #+#    #+#             */
/*   Updated: 2023/08/30 18:47:34 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_push;
	t_stack	*new_node;
	t_stack	*linking_nodes;
	t_stack 	*check_nodes;

	/*1) Check if there is one argument (at least), 
	if there is no arguments return 0.*/
	if (argc < 2)
		return (0);
	/*2) Check if the input made is correct (only numbers, no more than ONE parameter as zero,
	(parameter zero can be various numbers: 0, -0, +0, 00, -00, +00 and so on), so I need to check
	if there is only one parameter that follows the "rule" to be considered zero.*/
	if (!ft_checker_input(argv))
		printf("KO: Arguments invalids\n");
	else
		printf("OK: Arguments valids\n");
	/*3) Convert the argument into an integer and stores it inside a linked list.*/
	i = 0;
	while (argv[++i])
	{
		//3.1) Allocating the first value on the head of the struct.
		if (i == 1)
		{
			stack_push->value = ft_atoi(argv[i]);
			stack_push->next = NULL;
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
				//3.3) Linking the node created with a pointer.
				linking_nodes = stack_push;
				while (linking_nodes->next != NULL)
					linking_nodes = linking_nodes->next;
				linking_nodes->next = new_node;
				new_node->next = NULL;
			}
		}
	/*4) Checking if there is duplicated values*/
		check_nodes = stack_push;
		if (!ft_check_nodes_duplicated(check_nodes))
		{
			printf("KO: Numbers duplicated.\n");
			return (0);
		}
	}
	printf("OK: Nothing duplicated.\n");
	return (0);
}
