/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:47:31 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/18 22:45:25 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




void	ft_print(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int	trigger;

	temp = *stack_a;
	printf("========================================\n");
	trigger = 1;
	printf("STACK_A:\n");
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != *stack_a || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("\n");
	temp = *stack_b;
	trigger = 1;
	printf("STACK_B:\n");
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != *stack_b || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("========================================\n");
	printf("\n");
}



void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size_stack)
{
	if (size_stack == 2 && !ft_is_sorted(*stack_a))
		do_sa(stack_a);
	else if (size_stack == 3)
		sort_three(stack_a);
	else if (size_stack == 4)
		sort_four(stack_a, stack_b);
	else if (size_stack == 5)
		sort_five(stack_a, stack_b);
	else
		sort_over_five(stack_a, stack_b);

}

int	main(int argc, char **argv)
{
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	/*1) Check if there is one argument (at least), 
	if there is no arguments return 0.*/
	if (argc < 2)
		return (0);
	/*2) Check if the input made is correct (only numbers)*/
	if (!ft_checker_input(argv))
	{
		//ft_putstr_fd("KO: Arguments invalids\n", 1);
		return (0);
	}
	else
		//ft_putstr_fd("OK: Arguments valids\n", 1);
	if (argc == 2)
		return (0);

	/*3) Convert the argument into an integer and stores it inside a linked list.*/
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	if (!stack_a)
		return (0);
	if(!ft_linking_nodes(argv, stack_a))
	{
		//ft_putstr_fd("KO: Couldn't Link the nodes.\n", 1);
		return (0);
	}
	else
		//ft_putstr_fd("OK: Linking done.\n", 1);
	/*4) Check if the values are duplicated only if there is more than 2 arguments passed.*/
	if (argc > 2)
	{
		if (!ft_check_nodes_duplicated(stack_a))
		{
			//ft_putstr_fd(ERROR_DUPLICATE, 1);
			return (0);
		}
		else
		{
			//ft_putstr_fd("OK: Nothing duplicated.\n", 1);
		}
	}
	/*5) Set the ideal position (index) on each node.*/
	ft_set_index(argc, stack_a);

	/*6) Check if the order of the stack_a is already sorted.*/
	if (ft_is_sorted (stack_a))
	{
		//ft_putstr_fd("OK: Is sorted!\n", 1);
		return (0);
	}
	else
		//ft_putstr_fd("KO: It's not sorted!\n", 1);
	
	/*7) Defining the size of each stack.*/

	size_a = ft_size_stack(stack_a);
	size_b = ft_size_stack(stack_b);
	/*8) Calling the main function to sort the numbers.*/
	ft_push_swap(&stack_a, &stack_b, size_a);
	//ft_print(&stack_a, &stack_b);
	return (0);
}
