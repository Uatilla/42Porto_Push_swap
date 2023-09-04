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

/*MY GOAL:
	-> 

	-> */

#include <stdio.h>

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
	if (*s1 == '-' && *s2 == '-')
	{
		while(*s1 == '-' || *s1 == '0')
			s1++;
		while(*s2 == '+' || *s2 == '0')
			s2++;
	}
	while (*s1 == '+' || *s1 == '0')
		s1++;
	while (*s2 == '+' || *s2 == '0')
		s2++;
	while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))
	{
        s1++;
        s2++;
    }
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

static	int	ft_check_duplicated(char **arg_List)
{
	int	i;
	int	j;

	i = 1;
	while (arg_List[i])
	{
		j = i + 1;
		while (arg_List[j])
		{
			//In the If position must be a String compare.
			if (!ft_strcmp(arg_List[i], arg_List[j]))
				return (0);
			j++;
		}
		i++;
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
	if (!ft_check_duplicated(arg_List))
		return (0);
	return(1);
}

int	main(int argc, char **argv)
{
	//1) Check if there is one argument (at least), if there is no parameters informed return 0.
	if(argc < 2)
		return (0);
	/*2) Check if the input made is correct (only numbers, no more than ONE parameter zero,
	(parameter zero can be various numbers: 0, -0, +0, 00, -00, +00 and so on), so I need to check
	if there is only one parameter that follows the "rule" to be considered zero.*/

	if(!ft_checker_input(argv))
	{
		printf("Error in the input!\t I have to do a free in the stack_a and stack_b");
	}
	else
	{
		printf("Check done, successfully!");
	}
	return (0);
}
