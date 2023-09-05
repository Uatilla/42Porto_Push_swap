/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:36:41 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/05 19:36:43 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker_input(char **arg_List)
{
	int	i;
	int	zero_counter;

	i = 1;
	zero_counter = 0;
	while (arg_List[i])
	{
		/*2.1) Check if the argument is only made of numbers.*/
		if (!ft_isanumber(arg_List[i]))
			return (0);
		/*2.2) Check if only one argument can be defined as zero:
		(+0, 0, -0, +00, 00, -00), otherwise return error (0);*/
		zero_counter += ft_is_zeroes(arg_List[i]);
		i++;
	}
	if (zero_counter > 1)
		return (0);
	return (1);
}

int	ft_is_sign(char first_Char)
{
	if (first_Char == '-' || first_Char == '+')
		return (1);
	return (0);
}

int	ft_is_zeroes(char *arg_String)
{
	int	i;

	i = 0;
	if (ft_is_sign(arg_String[i]) && arg_String[i + 1] != '\0')
		i++;
	while (arg_String[i] && arg_String[i] == '0')
		i++;
	if (arg_String[i] != '\0')
		return (0);
	return (1);
}

int	ft_isdigit(int arg_Char)
{
	return (arg_Char >= '0' && arg_Char <= '9');
}

int	ft_isanumber(char *arg_String)
{
	int	i;

	i = 0;
	while (arg_String[i])
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

int	ft_check_nodes_duplicated(t_stack *check_nodes)
{
	int		current_value;
	t_stack	*temp;

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
