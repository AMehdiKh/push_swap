/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/23 20:13:23 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a[1];
	t_stack	b[1];

	if (ac < 5)
		return (0);
	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));
	ft_check_args(a, b, ac, av);
	b->stack = malloc(a->size * sizeof(int));
	if (!b->stack)
		ft_err(a, NULL, NULL);
	// if (a->size <= 5)
	// {
	// 	ft_sort_eq_less_5(a, b);
	// }
	// else
	ft_sort(a, b);
	free(b->stack);
	free(a->stack);
	return (0);
}

int	ft_index(t_stack *ptr, int rank)
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

void	ft_sort(t_stack *a, t_stack *b)
{
	int	range;
	int	i;

	range = 2;
	i = 0;
	while (a->size)
	{
		if (a->stack[0] < i)
		{
			ft_pb(a, b);
			ft_rb(b, 1);
			++i;
		}
		else if (a->stack[0] < range + i)
		{
			ft_pb(a, b);
			++i;
		}
		else
			ft_ra(a, 1);
	}
	while (b->size)
	{
		if (ft_index(b, b->size - 1) < b->size / 4)
			while (ft_index(b, b->size - 1) != 0)
				ft_rb(b, 1);
		else
			while (ft_index(b, b->size - 1) != 0)
				ft_rrb(b, 1);
		ft_pa(a, b);
	}
}

// void	ft_khra(t_stack *a)
// {
// 	int	i;

// 	i = 0;
// 	printf("\n##################\n");
// 	while(i < a->size)
// 	{
// 		printf("\na ->%d\n", a->stack[i++]);
// 	}
// 	printf("\nsize ->%d\n", a->size);

// 	printf("\n##################\n");
// }
// void	ft_sort_2(t_data *data)
// {
// 	ft_sa(data, 1);
// }

// void	ft_sort_3(t_stack *a)
// {
// 	if (ft_index(a, 2) == 1)
// 		ft_sa(a, 1);
// 	if (ft_index(a, 2) == 0)
// 		ft_ra(a, 1);
// 	if (ft_index(a, 0) == 1)
// 		ft_sa(a, 1);
// }

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
		ft_pb(a, b);
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
		ft_pa(a, b);
}

int	ft_sorted(t_stack *ptr)
{
	int	i;

	i = 0;
	while (++i < ptr->size)
		if (ptr->stack[i - 1] > ptr->stack[i])
			return (0);
	return (1);
}

	// while (i < a->size)
	// {
	// 	if (ft_index(a, i) <= a->size / 2)
	// 		while (ft_index(a, i) != 0)
	// 			ft_ra(a, 1);
	// 	else
	// 		while (ft_index(a, i) != 0)
	// 			ft_rra(a, 1);
	// 	ft_pb(a, b);
	// 	++i;
	// }

// 78 92 9 63 30 50 77 74 8 70 19 100 79 32 31 25 59 10 42 14 86 39 24 43 69 5 91 47 88 33 73 62 2 49 13 34 35 68 52 37 75 53 85 21 82 45 51 97 46 36 72 66 28 71 23 81 90 20 93 56 76 40 29 38 15 16 60 55 7 6 12 48 1 41 99 11 95 18 54 26 84 57 3 58 64 98 96 65 83 61 89 27 4 87 17 44 94 80 67 2278 92 9 63 30 50 77 74 8 70 19 100 79 32 31 25 59 10 42 14 86 39 24 43 69 5 91 47 88 33 73 62 2 49 13 34 35 68 52 37 75 53 85 21 82 45 51 97 46 36 72 66 28 71 23 81 90 20 93 56 76 40 29 38 15 16 60 55 7 6 12 48 1 41 99 11 95 18 54 26 84 57 3 58 64 98 96 65 83 61 89 27 4 87 17 44 94 80 67 2278 92 9 63 30 50 77 74 8 70 19 100 79 32 31 25 59 10 42 14 86 39 24 43 69 5 91 47 88 33 73 62 2 49 13 34 35 68 52 37 75 53 85 21 82 45 51 97 46 36 72 66 28 71 23 81 90 20 93 56 76 40 29 38 15 16 60 55 7 6 12 48 1 41 99 11 95 18 54 26 84 57 3 58 64 98 96 65 83 61 89 27 4 87 17 44 94 80 67 22