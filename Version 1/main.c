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

#include <stdio.h>
#include <stdlib.h>
/*MY GOAL:
	-> 

	-> */


typedef struct s_push
{
	int value;
	int	index;
	struct s_push *next;
} t_stack;

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	number;

	signal = 1;
	number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signal = signal * (-1);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number *= 10;
		number += *nptr - 48;
		nptr++;
	}
	return (signal * number);
}

int	ft_isdigit(int arg_Char)
{
	return (arg_Char >= '0' && arg_Char <= '9');
}

static	int ft_is_sign(char first_Char)
{
	if (first_Char == '-' || first_Char == '+')
		return (1);
	return(0);
}

static 	int	ft_isanumber(char *arg_String)
{
	int	i;

	i = 0;
	while(arg_String[i])
	{
		if (ft_is_sign(arg_String[i]) && arg_String[i + 1] != '\0')
			i++;
		while (arg_String[i] && ft_isdigit(arg_String[i]))
			i++;
		if (arg_String[i] != '\0')
			return (0);
	}
	return (1);
}
static	int	ft_is_zeroes(char *arg_String)
{
	int	i;

	i = 0;
	if (ft_is_sign(arg_String[i]) && arg_String[i + 1] != '\0')
		i++;
	while(arg_String[i] && arg_String[i] == '0')
		i++;
	if (arg_String[i] != '\0')
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))
	{
        s1++;
        s2++;
    }
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

static	int	ft_check_duplicated(int *array_ints, int size)
{
	int	i;
	int	j;

	i = -1;
	while (array_ints[++i] && i < size)
	{
		j = i;
		while (array_ints[++j] && i < size)
			if (array_ints[i] == array_ints[j])
				return (0);
	}
	return (1);
}

static int ft_check_nodes_duplicated(t_stack *check_nodes)
{
	int	current_value;
	t_stack *temp;

	while (check_nodes != NULL)
	{
		temp = check_nodes->next;
		while (temp != NULL)
		{
			if (check_nodes->value == temp->value)
				return (0);
			temp = temp->next;
		}
		check_nodes = check_nodes->next;
	}
	return (1);
}

static	int	ft_checker_input(char **arg_List)
{
	int	i;
	int	zero_counter;

	i = 1;
	zero_counter = 0;
	while(arg_List[i])
	{
		if(!ft_isanumber(arg_List[i]))
			return (0);
		zero_counter += ft_is_zeroes(arg_List[i]);
		i++;
	}
	//2.1) If I found more than on argument that fits the zero (+0, 0, -0, +00, 00, -00), then return error (0);
	if (zero_counter > 1)
		return (0);
	/*if (!ft_check_duplicated(arg_List))
		return (0);*/
	
	return(1);
}

int	main(int argc, char **argv)
{
	int	i;
	//int	array_ints[argc - 1];


	//1) Check if there is one argument (at least), if there is no parameters informed return 0.
	if(argc < 2)
		return (0);
	/*2) Check if the input made is correct (only numbers, no more than ONE parameter zero,
	(parameter zero can be various numbers: 0, -0, +0, 00, -00, +00 and so on), so I need to check
	if there is only one parameter that follows the "rule" to be considered zero.*/

	if(!ft_checker_input(argv))
		printf("KO: Arguments invalids\n");
	else
		printf("OK: Arguments ok\n");
	/*3) Convert the argument into an integer and stores it inside an integer array.*/

	//USING ARRAY OF INTEGERS
	/*i = 1;
	while (argv[i])
	{
		array_ints[i - 1] = ft_atoi(argv[i]);
		i++;
	}*/
	/*4)Check if the inputs are duplicated.*/
	/*if(!ft_check_duplicated(array_ints, argc - 1))
		return (0);
	else
		printf("nothing duplicated\n");*/

	//USING STRUCT
	t_stack *stack_push;
	i = 0;
	while (argv[++i])
	{
		//Allocating the first value on the head.
		if (i == 1)
		{
			stack_push->value = ft_atoi(argv[i]);
			stack_push->next = NULL;
		}
		else
		{	
			//creating a new node
			t_stack *new_node = malloc(sizeof(t_stack));
			if (!new_node)
				return (0);
			else
			{
				new_node->value = ft_atoi(argv[i]);
				//linking the node created with a pointer.
				t_stack *linking_nodes = stack_push;
				while (linking_nodes->next != NULL)
					linking_nodes = linking_nodes->next;
				linking_nodes->next = new_node;
				new_node->next = NULL;
			}
		}
	/*4) Checking if there is duplicated values*/
	t_stack *check_nodes = stack_push;
	if(!ft_check_nodes_duplicated(check_nodes))
	{
		printf("KO: Numbers duplicated.\n");
		return (0);
	}
	printf("OK: Nothing duplicated.\n");
	}
	return (0);
}
