/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:47:31 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/08 20:09:33 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	//do_sa(stack_a);
	//do_pa(stack_a, stack_b);
	//do_ra(stack_a);
	//do_rra(stack_a);
}

int	main(int argc, char **argv)
{
	int		trigger;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *print_a;
	t_stack *print_b;
	t_stack	*temp;

	/*1) Check if there is one argument (at least), 
	if there is no arguments return 0.*/
	if (argc < 2)
		return (0);
	/*2) Check if the input made is correct (only numbers)*/
	if (!ft_checker_input(argv))
	{
		printf("KO: Arguments invalids\n");
		return (0);
	}
	else
		printf("OK: Arguments valids\n");
	if (argc == 2)
		return (0);

	/*3) Convert the argument into an integer and stores it inside a linked list.*/
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	if (!stack_a)
		return (0);
	if(!ft_linking_nodes(argv, stack_a))
	{
		printf("KO: Couldn't Link the nodes.\n");
		return (0);
	}
	else
		printf("OK: Linking done.\n");
		/*4) Check if the values are duplicated only if there is more than 2 arguments passed.*/
	if (argc > 2)
	{
		if (!ft_check_nodes_duplicated(stack_a))
		{
			printf("KO: Numbers duplicated.\n");
			return (0);
		}
		else
			printf("OK: Nothing duplicated.\n");
	}
	/*5) Set the ideal position (index) on each node.*/
	ft_set_index(argc, stack_a);

	if (ft_is_sorted (stack_a))
		printf("OK: Is sorted!\n");
	else
		printf("KO: It's not sorted!\n");
	

	//PRINTING THE OPERATIONS:
	print_a = stack_a;
	print_b = stack_b;
	trigger = 1;
	printf("BEFORE - STACK A!\n");
    while(print_a && (trigger == 1 || print_a != stack_a))
    {
		trigger = 0;
        printf("[%d]: %d\t", print_a->index, print_a->value);
		print_a = print_a->next;
    }
	printf("\n");

	trigger = 1;
	printf("BEFORE - STACK B!\n");
    while(print_b && (trigger == 1 || print_b != stack_b))
    {
		trigger = 0;
        printf("[%d]: %d\t", print_b->index, print_b->value);
		print_b = print_b->next;
    }
	printf("\n");

	//Operations:
	ft_push_swap(&stack_a, &stack_b);
	
	print_a = stack_a;
	print_b = stack_b;
	trigger = 1;
	printf("AFTER - STACK A!\n");
    while(print_a && (trigger == 1 || print_a != stack_a))
    {
		trigger = 0;
        printf("[%d]: %d\t", print_a->index, print_a->value);
		print_a = print_a->next;
    }
	printf("\n");

	trigger = 1;
	printf("AFTER - STACK B!\n");
    while(print_b && (trigger == 1 || print_b != stack_b))
    {
		trigger = 0;
        printf("[%d]: %d\t", print_b->index, print_b->value);
		print_b = print_b->next;
    }
	printf("\n");
	return (0);
}
