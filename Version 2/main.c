/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:47:31 by uviana-a          #+#    #+#             */
/*   Updated: 2023/08/30 18:47:34 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_push;

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
		printf("KO: Failed to link the nodes\n");
		return (0);
	}
	else
	{
		printf("OK: Nodes linked correctly.\n");
	}
	
	/*4) Checking if there is duplicated values*/
	if (!ft_check_nodes_duplicated(stack_push))
	{
		printf("KO: Numbers duplicated.\n");
		return (0);
	}
	printf("OK: Nothing duplicated.\n");
    /*
    //PRINTING THE NODES:
    while(stack_push)
    {
        printf("\n Node [%d] = %d\n", i, stack_push->value);
        stack_push = stack_push->next;
        i++;
    }*/
	return (0);
}
