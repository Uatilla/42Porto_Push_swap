/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:52:45 by uviana-a          #+#    #+#             */
/*   Updated: 2023/09/12 18:53:03 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int ft_size_stack(t_stack *stack)
{
	t_stack *temp;
	int	trigger;
	int i;

	temp = stack;
	trigger = 1;
	i = 0;
	while (temp && (temp != stack || trigger == 1))
	{
		trigger = 0;
		i++;
		temp = temp->next;
	}
	return (i);
}
