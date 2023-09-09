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

static void	do_swap(t_stack **stack_push)
{
	t_stack	*tail;
	t_stack *old_head;
	t_stack	*new_head;

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



int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_push;
	t_stack *print;
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


	/*3) Convert the argument into an integer and stores it inside a linked list.*/
	stack_push = malloc(sizeof(t_stack));
	if (!stack_push)
		return (0);
	if(!ft_linking_nodes(argv, stack_push))
	{
		printf("KO: Couldn't Link the nodes.\n");
		return (0);
	}
	else
		printf("OK: Linking done.\n");
		/*4) Check if the values are duplicated only if there is more than 2 arguments passed.*/
	if (argc > 2)
	{
		if (!ft_check_nodes_duplicated(stack_push))
		{
			printf("KO: Numbers duplicated.\n");
			return (0);
		}
		else
			printf("OK: Nothing duplicated.\n");
	}
	/*5) Set the ideal position (index) on each node.*/
	ft_set_index(argc, stack_push);

	if (ft_is_sorted (stack_push))
		printf("OK: Is sorted!\n");
	else
		printf("KO: It's not sorted!\n");
	

	//PRINT BEFORE THE OPERATIONS:
	print = stack_push;
	i = 0;
	printf("BEFORE THE OPERATION - FORWARD!\n");
    while(i < argc - 1)
    {
        printf("[%d]: %d\t", print->index, print->value);
		print = print->next;
        i++;
    }
	printf("\n");
	/*i = 0;
	printf("BEFORE THE OPERATION - BACKWARD!\n");
	while(i < argc - 1)
    {
        print = print->prev;
		printf("[%d]: %d\t", print->index, print->value);
		
        i++;
    }*/
	//do_sa
	do_swap(&stack_push); //ONLY CALL THIS FUNCTION IF THERE'S ONE OR MORE NODES OR THE DATA ISN'T SORTED.
	print = stack_push;
	printf("\n");
	i = 0;
	printf("AFTER THE OPERATION - FORWARD!\n");
    while(i < argc - 1)
    {
        printf("[%d]: %d\t", print->index, print->value);
		print = print->next;
        i++;
    }
	/*printf("\n");
	i = 0;
	printf("AFTER THE OPERATION - BACKWARD!\n");
	while(i < argc - 1)
    {
        print = print->prev;
		printf("[%d]: %d\t", print->index, print->value);
		
        i++;
    }
	printf("\n");*/

	
	
	//Defining the index of each node.

	return (0);
}
