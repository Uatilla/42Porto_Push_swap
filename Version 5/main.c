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

void	set_total_cost(t_stack **stack_a)
{
	int	size_a;
	int	i;
	t_stack	*temp;

	i = 0;
	size_a = ft_size_stack(*stack_a);
	temp = *stack_a;
	while (i < size_a)
	{
		temp->total = temp->ra + temp->rb + temp->rr + temp->rra + temp->rrb + temp->rrr;
		temp = temp->next;
		i++;
	}
}

t_stack	*find_prev_index(t_stack **stack_b, int index)
{
	t_stack	*prev_index;
	int	trigger;
	int	i;

	
	i = 1;
	prev_index = *stack_b;
	while (1)
	{
		trigger = 1;
		while (trigger == 1 || prev_index != *stack_b)
		{
			trigger = 0;
			if (prev_index->index != index - i)
				prev_index = prev_index->next;
			else
				return (prev_index);
		}
		i++;
	}
}

void	setting_position_costs(t_stack **src, t_stack **dest, int size_a, int size_b)
{
	int	trigger;
	int	highest_index;
	int	lowest_index;
	t_stack *temp_a;
	t_stack	*temp_b;
	int	i;
	int	j;

	highest_index = ft_find_index(dest, 'H');
	lowest_index = ft_find_index(dest, 'L');
	temp_a = *src;
	temp_b = *dest;
	while (temp_b->index != highest_index)
		temp_b = temp_b->next;
	trigger = 1;
	i = 0;
	while (trigger == 1 || i < size_a)
	{
		trigger = 0;
		if (temp_a->index > highest_index || temp_a->index < lowest_index)
		{
			temp_a->rb = temp_b->ra;
			temp_a->rrb = temp_b->rra;
		}
		else
		{
			//temp_b = find_prev_index(stack_b, temp_a->index);
			j = 0;
			while (j < size_b)
			{
				if (temp_a->index > temp_b->index && temp_a->index < temp_b->prev->index)
				{
					temp_a->rb = temp_b->ra;
					temp_a->rrb = temp_b->rra;
				}
				temp_b = temp_b->next;
				j++;
			}
		}
			
		temp_a = temp_a->next;
		i++;
	}
}

void	setting_costs(t_stack **stack, int size)
{
	t_stack	*temp;

	temp = *stack;
	if (size % 2 == 0)
	{
		while (temp->pos <= size/2)
		{
			temp->ra = temp->pos - 1;
			temp->rra = 0;
			temp = temp->next;
		}
		while (temp->pos > size/2)
		{
			temp->rra = size - temp->pos + 1;
			temp->ra = 0;
			temp = temp->next;
		}
	}
	else
	{
		while (temp->pos <= (size/2) + 1)
		{
			temp->ra = temp->pos - 1;
			temp->rra = 0;
			temp = temp->next;
		}
		while (temp->pos > (size/2) + 1)
		{
			temp->rra = size - temp->pos + 1;
			temp->ra = 0;
			temp = temp->next;
		}
	}
}

void	setting_current_pos(t_stack **stack)
{
	t_stack	*head;
	int	trigger;
	int	i;

	head = *stack;
	trigger = 1;
	i = 0;
	while (++i && (head != *stack || trigger == 1))
	{
		trigger = 0;
		head->pos = i;
		head = head->next;
	}
}

void	ft_id_best_cost(t_stack **stack)
{
	t_stack	*temp_a;
	t_stack	*best_cost;
	int	size_a;
	int	i;

	temp_a = *stack;
	size_a = ft_size_stack(*stack);
	i = 0;
	while (i < size_a)
	{
		if (temp_a->ra != 0 && temp_a->rb != 0)
			{
				if (temp_a->ra > temp_a->rb)
				{
					temp_a->rr = temp_a->rb;
					temp_a->ra = temp_a->ra - temp_a->rb;
					temp_a->rb = 0;
				}
				else
				{
					temp_a->rr = temp_a->ra;
					temp_a->rb = temp_a->rb - temp_a->ra;
					temp_a->ra = 0;
				}
		
			}
		else
			temp_a->rr = 0;
		if (temp_a->rra != 0 && temp_a->rrb != 0)
			{
				if (temp_a->rra > temp_a->rrb)
				{
					temp_a->rrr = temp_a->rrb;
					temp_a->rra = temp_a->rra - temp_a->rrb;
					temp_a->rrb = 0;
				}
				else
				{
					temp_a->rrr = temp_a->rra;
					temp_a->rrb = temp_a->rrb - temp_a->rra;
					temp_a->rra = 0;
				}
			}
		else
			temp_a->rrr = 0;
		temp_a = temp_a->next;
		i++;
	}
}

t_stack	*ft_lowest_cost(t_stack **stack_a)
{
	int	i;
	int	j;
	int	trigger;
	t_stack	*temp;
	int	size_a;

	temp = *stack_a;
	
	i = -1;
	size_a = ft_size_stack(*stack_a);
	j = 0;
	while (temp->total != i)
	{
		i++;
		trigger = 1;
		while (temp->total != i && (trigger == 1 || temp != *stack_a))
		{
			trigger = 0;
			temp = temp->next;
		}
			if (temp->total == i)
				return (temp);
	}
	return (0);
}

void	do_operations(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->ra > 0)
	{
		do_ra(&*stack_a);
		temp->ra--;
	}
	while (temp->rb > 0)
	{
		do_rb(&*stack_b);
		temp->rb--;
	}
	while (temp->rr > 0)
	{
		do_rr(&*stack_a, &*stack_b);
		temp->rr--;
	}
	while (temp->rra > 0)
	{
		do_rra(&*stack_a);
		temp->rra--;
	}
	while (temp->rrb > 0)
	{
		do_rrb(&*stack_b);
		temp->rrb--;
	}

	while (temp->rrr > 0)
	{
		do_rrr(&*stack_a, &*stack_b);
		temp->rrr--;
	}
	do_pb(&*stack_a, &*stack_b);
}

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

void	return_to_stack_a(t_stack **src, t_stack **dest)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;
	int			i;
	int			lowest_index;
	int			highest_index;

	temp_a = *dest;
	temp_b = *src;

	size_b = ft_size_stack(temp_b);
	i = size_b;
	printf("SIZE: %d\n", size_b);
	while (size_b != 0)
	{
		lowest_index = ft_find_index(dest, 'L');
		highest_index = ft_find_index(dest, 'H');
		if (temp_b->index < lowest_index || temp_b->index > highest_index)
		{
			while (temp_a->index != highest_index)
				do_ra(&temp_a);
		}
		else if (temp_b->index < temp_a->index && temp_b->index > temp_a->prev->index)
		{
			//REVER A FUNCAO PA
			do_pa(&temp_b, &temp_a);
		}
		//corrigir para considerar tanto o ra quanto o rra
		else
			do_ra(&temp_a);
		//printf("SIZE_A: %d, SIZE_B: %d\n", ft_size_stack(temp_a), ft_size_stack(temp_b));
		size_b = ft_size_stack(temp_b);	
	}
}

void	sort_over_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;
	t_stack	*temp;
	int	highest_index;

	
	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
	//do_pb(stack_a, stack_b);
	//do_pb(stack_a, stack_b);
	//do_pb(stack_a, stack_b);
	//do_pb(stack_a, stack_b);
	size_a = ft_size_stack(*stack_a);
	while (size_a >= 4)
	{
		setting_current_pos(stack_a);
		setting_current_pos(stack_b);
		size_a = ft_size_stack(*stack_a);
		size_b = ft_size_stack(*stack_b);
		setting_costs(stack_a, size_a);
		setting_costs(stack_b, size_b);
		setting_position_costs(stack_a, stack_b, size_a, size_b);
		ft_id_best_cost(stack_a);
		set_total_cost(stack_a);
		temp = ft_lowest_cost(stack_a);
		if (!temp)
		{
			printf("Erro em encontrar o custo menor!\n");
			ft_print(stack_a, stack_b);
		}
		else
		{
			//printf("Lowest_cost: %d\n", temp->index);
			//ft_print(stack_a, stack_b);
		}
		do_operations(stack_a, stack_b, temp);
		size_a = ft_size_stack(*stack_a);
		
	}

	sort_three(stack_a);
	setting_current_pos(stack_b);
	size_b = ft_size_stack(*stack_b);
	temp = *stack_b;
	highest_index = ft_find_index(stack_b, 'H');
	while (temp->index != highest_index)
	{
		temp = temp->next;
	}
	while ((*stack_b) != temp)
	{
		if (temp->pos <= size_b / 2)
			do_ra(stack_b);
		else
			do_rra(stack_b);
	}
	//return_to_stack_a(stack_b, stack_a);
	temp = (*stack_a)->prev;
	while ((*stack_b)->index > temp->index && stack_b != NULL)
	{
		do_pa(stack_b, stack_a);
		if ((*stack_b)->index < temp->index)
		{
			do_rra(stack_a);
			//printf("temp index: %d\n", temp->index);
			temp = temp->prev;
		}
	}
	highest_index = ft_find_index(stack_a, 'H');
	while (*stack_b != NULL)
	{
		do_pa(stack_b, stack_a);
	}
	
	//ft_print(stack_a, stack_b);


}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size_stack)
{
	if (size_stack == 2 && !ft_is_sorted(*stack_a))
		do_sa(stack_a);
	else if (size_stack == 3)
		sort_three(stack_a);
	else if (size_stack == 4)
		sort_four(stack_a, stack_b);
		//On Sort_five I have to improve it to be able to solve the task with only 8 moves.
	else if (size_stack == 5)
		sort_five(stack_a, stack_b);
	else
		sort_over_five(stack_a, stack_b);

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
	
	/*7) Checking the size of each stack.*/

	size_a = ft_size_stack(stack_a);
	size_b = ft_size_stack(stack_b);
	
	//PRINTING THE STACK BEFORE THE OPERATIONS!:
	/*printf("====================| BEFORE |====================\n");
	temp = stack_a;
	trigger = 1;
	ft_putstr_fd("STACK_A:\n", 1);
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != stack_a || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("\n");
	temp = stack_b;
	trigger = 1;
	printf("STACK_B:\n");
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != stack_b || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("\n");
	printf("===================| MOVIMENTS |=================\n");*/

	ft_push_swap(&stack_a, &stack_b, size_a);
	//PRINTING THE STACK AFTER THE OPERATIONS!:
	/*printf("====================| AFTER |=====================\n");
	temp = stack_a;
	trigger = 1;
	printf("STACK_A:\n");
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != stack_a || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("\n");
	temp = stack_b;
	trigger = 1;
	printf("STACK_B:\n");
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != stack_b || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("\n");*/

	/*printf("====================| COST REVIEWED |=====================\n");
	temp = stack_a;
	trigger = 1;
	printf("STACK_A:\n");
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != stack_a || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("\n");
	temp = stack_b;
	trigger = 1;
	printf("STACK_B:\n");
	printf("Value:\tIndex:\tPos:\t|RA\tRB:\tRR:|\t|RRA:\tRRB:\tRRR:|\tT:\n");
	while (temp && (temp != stack_b || trigger == 1))
	{
		trigger = 0;
		printf("%d\t[%d]\t[%d]\t|[%d]\t[%d]\t[%d]|\t|[%d]\t[%d]\t[%d]|\t[%d]\n", temp->value, temp->index, temp->pos, temp->ra, temp->rb, temp->rr, temp->rra, temp->rrb, temp->rrr, temp->total);
		temp = temp->next;
	}
	printf("\n");*/
	return (0);
}
