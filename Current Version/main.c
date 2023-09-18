/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:47:31 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/12 09:01:03 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	idx_to_move;

	idx_to_move = 1;
	if (ft_is_sorted(*stack_a))
		return ;
	if ((*stack_a)->index == idx_to_move)
	{
		do_pb(stack_a, stack_b);
		idx_to_move = 2;
	}
	else if((*stack_a)->prev->index == idx_to_move)
		do_rra(stack_a);
	else if((*stack_a)->prev->prev->index == idx_to_move)
	{
		do_rra(stack_a);
		do_rra(stack_a);
	}
	
	while (idx_to_move <= 2)
	{
		while ((*stack_a)->index != idx_to_move)
			do_ra(stack_a);
		do_pb(stack_a, stack_b);
		idx_to_move++;
	}
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
	do_pa(stack_b, stack_a);
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

}

int	main(int argc, char **argv)
{
	int		trigger;
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;

	/*1) Check if thedre is one argument (at least), 
	if there is no arguments return 0.*/
	if (argc < 2)
		return (0);
	/*2) Check if the input made is correct (only numbers)*/
	if (!ft_checker_input(argv))
	{
		ft_putstr_fd("KO: Arguments invalids\n", 1);
		return (0);
	}
	else
		ft_putstr_fd("OK: Arguments valids\n", 1);
	if (argc == 2)
		return (0);

	/*3) Convert the argument into an integer and stores it inside a linked list.*/
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	if (!stack_a)
		return (0);
	if(!ft_linking_nodes(argv, stack_a))
	{
		ft_putstr_fd("KO: Couldn't Link the nodes.\n", 1);
		return (0);
	}
	else
		ft_putstr_fd("OK: Linking done.\n", 1);
		/*4) Check if the values are duplicated only if there is more than 2 arguments passed.*/
	if (argc > 2)
	{
		if (!ft_check_nodes_duplicated(stack_a))
		{
			ft_putstr_fd(ERROR_DUPLICATE, 1);
			return (0);
		}
		else
			ft_putstr_fd("OK: Nothing duplicated.\n", 1);
	}
	/*5) Set the ideal position (index) on each node.*/
	ft_set_index(argc, stack_a);

	/*6) Check if the order of the stack_a is already sorted.*/
	if (ft_is_sorted (stack_a))
	{
		ft_putstr_fd("OK: Is sorted!\n", 1);
		return (0);
	}
	else
		ft_putstr_fd("KO: It's not sorted!\n", 1);
	
	/*7) Checking the size of each stack.*/

	size_a = ft_size_stack(stack_a);
	size_b = ft_size_stack(stack_b);
	
	//PRINTING THE STACK BEFORE THE OPERATIONS!:
	printf("====================| BEFORE |====================\n");
	temp = stack_a;
	trigger = 1;
	ft_putstr_fd("STACK_A:   ", 1);
	while (temp && (temp != stack_a || trigger == 1))
	{
		trigger = 0;
		printf("%d\t", temp->value);
		temp = temp->next;
	}
	printf("\n");
	temp = stack_b;
	trigger = 1;
	printf("STACK_B:   ");
	while (temp && (temp != stack_b || trigger == 1))
	{
		trigger = 0;
		printf("%d\t", temp->value);
		temp = temp->next;
	}
	printf("\n");
	printf("===================| MOVIMENTS |=================\n");

	ft_push_swap(&stack_a, &stack_b, size_a);
	//PRINTING THE STACK AFTER THE OPERATIONS!:
	printf("====================| AFTER |=====================\n");
	temp = stack_a;
	trigger = 1;
	printf("STACK_A:   ");
	while (temp && (temp != stack_a || trigger == 1))
	{
		trigger = 0;
		printf("%d\t", temp->value);
		temp = temp->next;
	}
	printf("\n");
	temp = stack_b;
	trigger = 1;
	printf("STACK_B:   ");
	while (temp && (temp != stack_b || trigger == 1))
	{
		trigger = 0;
		printf("%d\t", temp->value);
		temp = temp->next;
	}
	printf("\n");
	return (0);
}
