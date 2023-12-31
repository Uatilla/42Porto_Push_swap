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

int	ft_clean(t_stack *stack_a)
{
	t_stack	*temp;

	if (ft_size_stack(stack_a) == 2)
	{
		free(stack_a->next);
		free(stack_a);
	}
	else
	{
		stack_a->prev->next = NULL;
		while (stack_a)
		{
			temp = stack_a->next;
			free(stack_a);
			stack_a = temp;
		}
	}
	return (0);
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

int	ft_validation(int argc, char **argv, t_stack *stack_a)
{
	if (argc == 1)
	{
		free(stack_a);
		return (0);
	}
	if (argv[1][0] == '\0' || !ft_checker_input(argv))
	{
		ft_putstr_fd("Error\n", 2);
		free(stack_a);
		return (0);
	}
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	if (!stack_a)
		return (0);
	if (!ft_validation(argc, argv, stack_a))
		return (0);
	if (!ft_linking_nodes(argv, stack_a) || !check_extr_int(stack_a)
		|| !ft_check_nodes_duplicated(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_clean(stack_a));
	}
	ft_set_index(argc, stack_a);
	if (ft_is_sorted (stack_a))
		return (ft_clean(stack_a));
	ft_push_swap(&stack_a, &stack_b, ft_size_stack(stack_a));
	ft_clean(stack_a);
	return (0);
}
