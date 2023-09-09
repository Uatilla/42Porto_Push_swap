/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:03:53 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/05 19:03:55 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*__________________________________[HEADERS]________________________________*/

# include <stdio.h>
# include <stdlib.h>

/*__________________________________[STRUCT] ________________________________*/

typedef struct s_push
{
	int		value;
	int		index;
	struct s_push	*next;
}	t_stack;

/*_________________________________[FUNCTIONS]_______________________________*/
/*-----------------------------*Mandatory Part I*----------------------------*/

//INPUT VALIDATION:*******************************************************

int	ft_checker_input(char **arg_List);

int	ft_isdigit(int arg_Char);

int	ft_is_sign(char first_Char);

int	ft_isanumber(char *arg_String);

//CONVERTING INTO INTEGER:************************************************

int	ft_atoi(const char *nptr);

//LINKING NODES:**********************************************************

int	ft_linking_nodes(char **argv, t_stack *stack_push);

//CHECKING DUPLICATED:****************************************************

int	ft_check_nodes_duplicated(t_stack *check_nodes);


#endif