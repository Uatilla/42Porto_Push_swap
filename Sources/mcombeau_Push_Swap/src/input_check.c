/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:27:24 by mcombeau          #+#    #+#             */
/*   Updated: 2023/08/29 22:07:01 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* arg_is_number:
*   Checks if the argument is a number. +1 1 and -1 are all valid numbers.
*   Return: 1 if the argument is a number, 0 if not.
*/
//GUIDE - 3.2) CHECK EACH CHAR OF THE ARGUMENT IF IT HAS A SIGN '-' OR '+' AND  IF IT'S A NUMBER
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	/*while(av[i])
	{
		printf("av[%d] is [%c]\n", i, av[i]);
		i++;
	}
	i = 0;*/
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: 1 if a duplicate is found, 0 if there are none.
*/
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
*   Checks the argument is a 0 to avoid 0 +0 -0 duplicates
*	and 0 0000 +000 -00000000 too.
*   Return: 1 if the argument is a zero, 0 if it contains
*	anything else than a zero.
*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* is_correct_input:
*   Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.
*/

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	//GUIDE - 3.1) WHILE THERE IS AV's CHECK EACH ARGUMENT IF IT'S A NUMBER OR A SEQUENCE OF ZEROS.
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		//GUIDE - 3.3) CHECK IF THERE IS A SEQUENCE OF ZEROS AND RETURN 0 IF THAT'S THE CASE.
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	//GUIDE - 3.4) COMPARE THE AV[1] WITH ALL ARGUMENTS, THEN INCREMENT TO AV[2] AND DO THE SAME COMPARISON.
	if (have_duplicates(av))
		return (0);
	return (1);
}
