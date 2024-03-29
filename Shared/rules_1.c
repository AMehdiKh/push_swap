/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:25:50 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/27 17:43:40 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_stack *a, int rule)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
		if (rule)
			ft_putendl_fd("sa", 1);
	}
}

void	ft_sb(t_stack *b, int rule)
{
	int	temp;

	if (b->size > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
		if (rule)
			ft_putendl_fd("sb", 1);
	}
}

void	ft_ss(t_stack *a, t_stack *b, int rule)
{
	if (a->size > 1 && b->size > 1)
	{
		ft_sa(a, 0);
		ft_sb(b, 0);
		if (rule)
			ft_putendl_fd("ss", 1);
	}
}

void	ft_pa(t_stack *a, t_stack *b, int rule)
{
	int	temp;
	int	i;

	if (b->size)
	{
		temp = b->stack[0];
		i = 0;
		while (++i < b->size)
			b->stack[i - 1] = b->stack[i];
		b->size -= 1;
		i = a->size;
		while (i)
		{
			a->stack[i] = a->stack[i - 1];
			--i;
		}
		a->stack[0] = temp;
		a->size += 1;
		if (rule)
			ft_putendl_fd("pa", 1);
	}
}

void	ft_pb(t_stack *a, t_stack *b, int rule)
{
	int	temp;
	int	i;

	if (a->size)
	{
		temp = a->stack[0];
		i = 0;
		while (++i < a->size)
			a->stack[i - 1] = a->stack[i];
		a->size -= 1;
		i = b->size;
		while (i)
		{
			b->stack[i] = b->stack[i - 1];
			--i;
		}
		b->stack[0] = temp;
		b->size += 1;
		if (rule)
			ft_putendl_fd("pb", 1);
	}
}
