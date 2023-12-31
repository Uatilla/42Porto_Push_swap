/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:03:53 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/18 21:21:18 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*__________________________________[HEADERS]________________________________*/

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

/*__________________________________[STRUCT] ________________________________*/

typedef struct s_push
{
	int				value;
	int				index;
	int				pos;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	int				total;
	int				is_freed;
	struct s_push	*next;
	struct s_push	*prev;
}	t_stack;

/*_________________________________[FUNCTIONS]_______________________________*/
/*-----------------------------*Mandatory Part I*----------------------------*/

//INPUT VALIDATION:*******************************************************

int		ft_checker_input(char **arg_List);

int		ft_isdigit(int arg_Char);

int		ft_is_sign(char first_Char);

int		ft_isanumber(char *arg_String);

//CONVERTING INTO INTEGER:************************************************

long long int		ft_atoi(const char *nptr);

//LINKING NODES:**********************************************************

int		ft_linking_nodes(char **argv, t_stack *stack_push);

//CHECKING DUPLICATED VALUES:*********************************************

int		ft_check_nodes_duplicated(t_stack *check_nodes);

//SETTING INDEXES:********************************************************

void	ft_set_index(int argc, t_stack *stack_push);

//CHECKING IF IT'S ALREADY SORTED:****************************************

int		ft_is_sorted(t_stack *stack_push);

//SORTING THE NUMBERS:****************************************************

void	do_sa(t_stack **stack_a);

void	do_sb(t_stack **stack_b);

void	do_ss(t_stack **stack_a, t_stack **stack_b);

void	do_pa(t_stack **stack_b, t_stack **stack_a);

void	do_pb(t_stack **stack_a, t_stack **stack_b);

void	do_ra(t_stack **stack_a);

void	do_rb(t_stack **stack_b);

void	do_rr(t_stack **stack_a, t_stack **stack_b);

void	do_rra(t_stack	**stack_a);

void	do_rrb(t_stack	**stack_b);

void	do_rrr(t_stack	**stack_a, t_stack **stack_b);

void	do_op_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *temp);

void	do_op_rev_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *temp);

//ALGOR FUNCTIONS:********************************************************

void	sort_three(t_stack **stack);

void	sort_four(t_stack **stack_a, t_stack **stack_b);

void	sort_five(t_stack **stack_a, t_stack **stack_b);

void	sort_over_five(t_stack **stack_a, t_stack **stack_b);

void	do_operations(t_stack **stack_a, t_stack **stack_b, t_stack *temp);

int		ft_find_index(t_stack **stack, char search);

//UTILS FUNCTIONS:********************************************************

char	**ft_split(char const *s, char c);

void	ft_putstr_fd(char *s, int fd);

int	ft_clean(t_stack *stack_a);

int		ft_size_stack(t_stack *stack);

int	check_extr_int(t_stack *stack_a);

# define ERROR_DUPLICATE "KO: Numbers duplicated.\n"

//COSTS FUNCTIONS:********************************************************

void	set_total_cost(t_stack **stack_a);

void	set_pos_cost(t_stack **src, \
	t_stack **dest, int size_a, int size_b);

void	setting_costs_even(t_stack **stack, int size);

void	setting_current_pos(t_stack **stack);

void	ft_id_best_cost(t_stack **stack);

void	ft_print(t_stack **stack_a, t_stack **stack_b);

t_stack	*ft_lowest_cost(t_stack **stack_a);

#endif
