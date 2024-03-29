/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:11:17 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/27 17:54:42 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_stack *a, int rule)
{
	int	temp;
	int	i;

	if (a->size > 1)
	{
		temp = a->stack[0];
		i = 0;
		while (++i < a->size)
			a->stack[i - 1] = a->stack[i];
		a->stack[a->size - 1] = temp;
		if (rule)
			ft_putendl_fd("ra", 1);
	}
}

void	ft_rb(t_stack *b, int rule)
{
	int	temp;
	int	i;

	if (b->size > 1)
	{
		temp = b->stack[0];
		i = 0;
		while (++i < b->size)
			b->stack[i - 1] = b->stack[i];
		b->stack[b->size - 1] = temp;
		if (rule)
			ft_putendl_fd("rb", 1);
	}
}

void	ft_rr(t_stack *a, t_stack *b, int rule)
{
	if (a->size > 1 && b->size > 1)
	{
		ft_ra(a, 0);
		ft_rb(b, 0);
		if (rule)
			ft_putendl_fd("rr", 1);
	}
}

void	ft_rra(t_stack *a, int rule)
{
	int	temp;
	int	i;

	if (a->size > 1)
	{
		temp = a->stack[a->size - 1];
		i = a->size - 1;
		while (i)
		{
			a->stack[i] = a->stack[i - 1];
			--i;
		}
		a->stack[0] = temp;
		if (rule)
			ft_putendl_fd("rra", 1);
	}
}

void	ft_rrb(t_stack *b, int rule)
{
	int	temp;
	int	i;

	if (b->size > 1)
	{
		temp = b->stack[b->size - 1];
		i = b->size - 1;
		while (i)
		{
			b->stack[i] = b->stack[i - 1];
			--i;
		}
		b->stack[0] = temp;
		if (rule)
			ft_putendl_fd("rrb", 1);
	}
}
