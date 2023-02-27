/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 07:50:44 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/27 16:35:58 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rank(t_stack *a, int *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (a->stack[i] != ptr[j] && j < a->size)
			++j;
		if (a->stack[i] == ptr[j])
			a->stack[i] = j;
		++i;
	}
}

int	ft_position(t_stack *ptr, int rank)
{
	int	i;

	i = 0;
	while (i < ptr->size)
	{
		if (ptr->stack[i] == rank)
			return (i);
		++i;
	}
	return (-1);
}

void	ft_err(t_stack *a, char **args, char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	ft_clear(args);
	free(a->stack);
	exit(EXIT_FAILURE);
}

void	ft_clear(char **ptr)
{
	int	i;

	if (ptr)
	{
		i = 0;
		while (ptr[i])
			free(ptr[i++]);
		free(ptr);
	}
}

void	ft_rrr(t_stack *a, t_stack *b, int rule)
{
	if (a->size > 1 && b->size > 1)
	{
		ft_rra(a, 0);
		ft_rrb(b, 0);
		if (rule)
			ft_putendl_fd("rrr", 1);
	}
}
