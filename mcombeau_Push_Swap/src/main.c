/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:04:00 by mcombeau          #+#    #+#             */
/*   Updated: 2023/08/31 20:55:41 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* main:
*	Checks if the input is correct, in which case it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. When sorting is done, frees
*	the stacks and exits.
*/
int	main(int ac, char **av)
{
	//GUIDE - 1) BUILD TWO STRUCTS OF TYPE T_STRUCT (DECLARED IN PUSH_SWAP.H)
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	//GUIDE - 2) CHECK IF ANY ARGUMENT WAS PASSED (IF NONE, AC <= 2) RETURN 0.
	if (ac < 2)
		return (0);
	//GUIDE - 3) CHECK IF THE INPUT IS VALID (DECLARED IN INPUT_CHECK.C) SENDING ALL AV'S VALUES AT ONCE.
	/*int	i = 0;
	while(av[i] != NULL)
	{
		printf("av[%d] is [%s]\n", i, av[i]);
		i++;
	}*/
	//GUIDE - 4) IF THE INPUTS WERE INVALID, FREE THE STRUCTS T_STACK (A AND B).
	if (!is_correct_input(av))
		exit_error(NULL, NULL);

	//STOP


	
	//GUIDE - 5) stack_b is equal to a NULL pointer.
	stack_b = NULL;
	//GUIDE - 6) stack_a is filled with the function fill_stack_values (initialization.c)
	stack_a = fill_stack_values(ac, av);
	//GUIDE - 7) Get the size of the stack inside (stack.c) IT RUN'S ALL NODES OF THE STACK A.
	stack_size = get_stack_size(stack_a);
	//GUIDE - 8) 
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	/*while(stack_a->next != NULL)
	{
		printf("%d ",stack_a->value);
		stack_a = stack_a->next;
	}
	if (stack_a->next == NULL)
		printf("%d\n", stack_a->value);*/

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
