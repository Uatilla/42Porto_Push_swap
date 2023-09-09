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
    
    //PRINTING THE NODES:
	print = stack_push;
    while(print)
    {
        printf("Node [%d] = %d\t", i, print->value);
        print = print->next;
        i++;
    }

	/*5) Programming the sort functions*/
	/*print = stack_push;
	//do_sa
	temp = print->next;
	print->next = temp->next;
	temp->next = print;
	i = 0;
	printf("\n");
	 while(temp)
    {
        printf("Node [%d] = %d\t", i, temp->value);
        temp = temp->next;
        i++;
    }*/


	return (0);
}
