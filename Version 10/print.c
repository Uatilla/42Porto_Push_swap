/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:33:34 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/01 18:33:37 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		trigger;

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
