/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:44:42 by mcombeau          #+#    #+#             */
/*   Updated: 2023/08/31 21:56:08 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* fill_stack_values:
*	Fills stack_a with the provided values.
*	If the values are out of integer range, prints and error and exits the program.
*/
t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		//GUIDE - 6.1) the Variable nb receives the argument in the i position converted into integer.
		nb = ft_atoi(av[i]);
		//GUIDE - 6.2) IF the int informed is bigger or lower than what an int can receive return error.
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		//GUIDE - 6.3) If it's the first value of the stack_a (first node) create a new node with nb as a content.
		if (i == 1)
			stack_a = stack_new((int)nb);
		//GUIDE - 6.4 If isn't the first node, alocate the new node in the sequence on the stack_a.
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* assign_index:
*	Assigns an index to each value in stack a. This is a convenient way to order
*	the stack because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from highest (stack_size) to lowest (1).
*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		//The main goal here is to set the stack_size inside the stack (from the highest to the lowest)


		//GUIDE - 8.8) Return the ptr to the stack_a position and do the process again from 8.1
		// GUIDE - 8.1) Making a temp pointer to stack_a.
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		//The main GOAL of this while is try to set the index on the first number (if it's possible),
		// and set the highest index.
		while (ptr)
		{
			//GUIDE - 8.2) ROUND 0 - If the ptr.value is the minimun INT possible it's index should be 1.
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			//GUIDE - 8.3) ROUND 0 - Checking if current ptr.value is the biggest ptr.value until now and the index is 0 at start. 
			if (ptr->value > value && ptr->index == 0)
			{
				//GUIDE - 8.4) ROUND 0 - Set the value as ptr.value and the highest as the current ptr position.
				value = ptr->value;
				highest = ptr;
				//GUIDE - 8.5) ROUND 0 - reseting the ptr position to redo all validations.
				ptr = stack_a;
			}
			//GUIDE - 8.6) ROUND 1 - As setted on GUIDE 8.4 the value = ptr.value and on the GUIDE 8.5 
			//ptr restart to the stack_a position, so the program needs to change to the next position.
			else
				ptr = ptr->next;
		}
		// GUIDE - 8.7) Setting the index on the highest number.
		//On th step 8.4 you setted the highest number inside the struct now, you are setting it's index.
		//Pointer highest > ptr > stack_a
		if (highest != NULL)
			highest->index = stack_size;
	}
}
