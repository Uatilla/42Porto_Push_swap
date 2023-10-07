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

int	ft_validation(int argc, char **argv, t_stack *stack_a)
{
	/*1) Check if there is no argument, or one argument*/
	if (argc == 1)
	{
		free(stack_a);
		return (0);
	}
	/*2) Check if the input is empty or if it's only numbers.*/
	if (argv[1][0] == '\0' || !ft_checker_input(argv))
	{
		
		ft_putstr_fd("Error\n", 2);
		free(stack_a);
		return (0);
	}
	/*3) Check if there is only one argument and it's biggest or smallest
	than an Int variable.*/
	if (argc == 2)
	{
		if ((ft_atoi(argv[1]) < 2147483647) && (ft_atoi(argv[1]) > -2147483648))
			free(stack_a);
		else
		{
			ft_putstr_fd("Error\n", 2);
			free(stack_a);
		}
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		size_a;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;

	if (!stack_a)
		return (0);

	/*0) Validating the input.*/
	if (!ft_validation(argc, argv, stack_a))
		return (0);
	/*4) Convert the argument into an integer and stores it inside a linked list.*/
	/*5) Check if the values are duplicated only if there is more than 2 arguments passed.*/
	if (!ft_linking_nodes(argv, stack_a) || !check_extr_int(stack_a)
		|| !ft_check_nodes_duplicated(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_clean(stack_a));
	}
	
	/*6) Set the ideal position (index) on each node.*/
	ft_set_index(argc, stack_a);
	/*7) Check if the order of the stack_a is already sorted.*/
	if (ft_is_sorted (stack_a))
		return (ft_clean(stack_a));
	/*8) Defining the size of each stack.*/
	size_a = ft_size_stack(stack_a);
	/*9) Calling the main function to sort the numbers.*/
	ft_push_swap(&stack_a, &stack_b, size_a);
	ft_clean(stack_a);
	//ft_print(&stack_a, &stack_b);

	return (0);
}
