/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/25 07:06:46 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a[1];
	t_stack	b[1];

	if (ac < 1)
		return (0);
	ft_bzero(a, sizeof(t_stack));
	ft_check_args(a, ac, av);
	b->size = 0;
	b->stack = malloc(a->size * sizeof(int));
	if (!b->stack)
		ft_err(a, NULL, NULL);
	if (a->size <= 5)
		ft_sort_eq_less_5(a, b);
	else if (a->size <= 100)
		ft_range_sort(a, b, 15);
	else if (a->size <= 500)
		ft_range_sort(a, b, 35);
	free(a->stack);
	free(b->stack);
	return (0);
}

void	ft_sort_eq_less_5(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->size != 3)
	{
		if (ft_index(a, i) <= a->size / 2)
			while (ft_index(a, i) != 0)
				ft_ra(a, 1);
		else
			while (ft_index(a, i) != 0)
				ft_rra(a, 1);
		ft_pb(a, b, 1);
		++i;
	}
	if (ft_index(a, (a->size - 1) + b->size) == 0)
		ft_ra(a, 1);
	if (ft_index(a, (a->size - 1) + b->size) == 1)
		ft_rra(a, 1);
	if (ft_index(a, b->size) == 1)
		ft_sa(a, 1);
	if (ft_index(b, 0) == 0)
		ft_sb(b, 1);
	while (b->size)
		ft_pa(a, b, 1);
}

void	ft_range_sort(t_stack *a, t_stack *b, int range)
{
	ft_push_to_b(a, b, range);
	while (b->size)
	{
		if (ft_index(b, b->size - 1) <= b->size / 2)
			while (ft_index(b, b->size - 1) != 0)
				ft_rb(b, 1);
		else
			while (ft_index(b, b->size - 1) != 0)
				ft_rrb(b, 1);
		ft_pa(a, b, 1);
	}
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
		else if (a->stack[0] < range + i)
		{
			ft_pb(a, b, 1);
			++i;
		}
		else
			ft_ra(a, 1);
	}
}

// void	ft_sort_3(t_stack *a)
// {
// 	if (ft_index(a, 2) == 1)
// 		ft_sa(a, 1);
// 	if (ft_index(a, 2) == 0)
// 		ft_ra(a, 1);
// 	if (ft_index(a, 0) == 1)
// 		ft_sa(a, 1);
// }