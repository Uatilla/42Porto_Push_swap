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

int	ft_isdigit(int elmt)
{
	return (elmt >= '0' && elmt <= '9');
}

static	int ft_is_sign(char fst_elmt)
{
	return(fst_elmt == '-' || fst_elmt == '+');
}

static 	int	ft_isanumber(char *one_argument)
{
	int	i;

	i = 0;
	while(one_argument[i])
	{
		if (ft_is_sign(one_argument[i]) && one_argument[i + 1] != '\0')
			i++;
		while (one_argument[i] && ft_isdigit(one_argument[i]))
			i++;
		if (one_argument[i] != '\0')
			return (0);
	}
	return (1);
}
/*static	int	ft_is_zeroes(char *one_argument)
{

}*/

static	int	ft_checker_input(char **all_arguments)
{
	int	i;

	i = 1;
	while(all_arguments[i])
	{
		if(!ft_isanumber(all_arguments[i]))
			return (0);
		if(!ft_is_zeroes(all_arguments[i]))
			return (0);
		i++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	//If there is no parameters passed.
	if(argc < 2)
		return (0);
	/*Check the content:
		*DONE It has a sign ('-' or '+')?
		*DONE It's a number?
		*It's a sequence of zero 0000 or -00 or +0 or -0 or +0 and so on?
		*It's a number duplicated?
		*/
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
