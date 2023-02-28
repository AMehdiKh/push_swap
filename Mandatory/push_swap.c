/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/28 02:37:11 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a[1];
	t_stack	b[1];

	if (ac == 1)
		return (0);
	ft_check_args(ft_memset(a, 0, sizeof(t_stack)), ac, av);
	if (a->size == 1)
	{
		free(a->stack);
		exit(EXIT_SUCCESS);
	}
	ft_check_dup(a, 1);
	b->stack = ft_rank_stack(a);
	b->size = 0;
	if (a->size <= 15)
		ft_sort_small(a, b);
	else if (a->size <= 100)
		ft_range_sort(a, b, 19);
	else if (a->size <= 500)
		ft_range_sort(a, b, 35);
	free(a->stack);
	free(b->stack);
	return (0);
}

void	ft_sort_small(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->size > 3)
	{
		if (ft_position(a, i) <= a->size / 2)
			while (ft_position(a, i) != 0)
				ft_ra(a, 1);
		else
			while (ft_position(a, i) != 0)
				ft_rra(a, 1);
		ft_pb(a, b, 1);
		++i;
	}
	if (ft_position(a, (a->size - 1) + b->size) == 1)
		ft_rra(a, 1);
	if (ft_position(a, (a->size - 1) + b->size) == 0)
		ft_ra(a, 1);
	if (ft_position(a, b->size) == 1)
		ft_sa(a, 1);
	while (b->size)
		ft_pa(a, b, 1);
}

void	ft_push_to_b(t_stack *a, t_stack *b, int range)
{
	int	i;

	i = 0;
	while (a->size)
	{
		if (a->stack[0] < i)
		{
			ft_pb(a, b, 1);
			ft_rb(b, 1);
			++i;
		}
		else if (a->stack[0] < (range + i))
		{
			ft_pb(a, b, 1);
			++i;
		}
		else
			ft_ra(a, 1);
	}
}

void	ft_range_sort(t_stack *a, t_stack *b, int range)
{
	ft_push_to_b(a, b, range);
	while (b->size)
	{
		if (ft_position(b, b->size - 1) <= b->size / 2)
			while (ft_position(b, b->size - 1) != 0)
				ft_rb(b, 1);
		else
			while (ft_position(b, b->size - 1) != 0)
				ft_rrb(b, 1);
		ft_pa(a, b, 1);
	}
}
