/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:03:53 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/12 08:59:22 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*__________________________________[HEADERS]________________________________*/

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

/*__________________________________[STRUCT] ________________________________*/

typedef struct s_push
{
	int		value;
	int		index;
	int		head;
	struct s_push	*next;
	struct s_push	*prev;
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

//CHECKING DUPLICATED VALUES:*********************************************

int	ft_check_nodes_duplicated(t_stack *check_nodes);

//SETTING INDEXES:********************************************************

void	ft_set_index(int argc, t_stack *stack_push);

//CHECKING IF IT'S ALREADY SORTED:****************************************

int	ft_is_sorted(t_stack *stack_push);

//SORTING THE NUMBERS:****************************************************

void	do_sa(t_stack **stack_a);

void	do_sb(t_stack **stack_b);

void	do_pa(t_stack **stack_b, t_stack **stack_a);

void	do_pb(t_stack **stack_a, t_stack **stack_b);

void	do_ra(t_stack **stack_a);

void	do_rra(t_stack	**stack_a);

#endif
