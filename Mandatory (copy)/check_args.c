/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:34:05 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/20 19:51:04 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(t_stack *a, int ac, char **av)
{
	char	**args;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			ft_err(a, args, NULL);
		if (!*args)
			ft_err(a, args, "Error");
		j = -1;
		while (args[++j])
			ft_add_back(a, a->size + j, ft_atol(a, args, args[j]), args);
		ft_clear(&args);
		a->size += j;
	}
	if (a->size == 1)
	{
		free(a->stack);
		exit(EXIT_SUCCESS);
	}
	check_dup(a);
	ft_rank_stack(a);
}

long	ft_atol(t_stack *a, char **args, const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	if (ft_isdigit(*s))
		while (ft_isdigit(*s))
			result = (result * 10) + (*s++ - 48);
	result *= sign;
	if (*s || result > INT_MAX || result < INT_MIN)
		ft_err(a, args, "Error");
	return (result);
}

void	check_dup(t_stack *a)
{
	int	i;
	int	j;
	int	sorted;

	sorted = 1;
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->stack[i] > a->stack[j] && sorted);
				sorted = 0;
			if (a->stack[i] == a->stack[j])
				ft_err(data, NULL, "Error");
			++j;
		}
		++i;
	}
	if (sorted)
	{
		free(a->stack);
		exit(EXIT_SUCCESS);
	}
}

void	ft_err(t_stack *a, char **args, char *str)
{
	if (str)
		ft_putendl_fd("Error", 2);
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

void	ft_rank_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	min;

	b->stack = malloc((a->size + 1) * sizeof(int));
	if (!b->stack)
		ft_err(data, NULL, NULL);
	i = -1;
	while (++i < a->size)
		b->stack[i] = a->stack[i];
	i = -1;
	while (++i < data->a_size)
	{
		min = i;
		j = i;
		while (++j < data->a_size)
			if (b->stack[min] > b->stack[j])
				min = j;
		j = b->stack[i];
		b->stack[i] = b->stack[min];
		b->stack[min] = j;
		ft_rank(a, ptr[i], i);
	}
	ft_bzero(b, sizeof(t_stack));
}

void	ft_rank(t_stack *a, int value, int rank)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] == value)
			a->stack[i] = rank;
		++i;
	}
}

void	ft_add_back(t_stack *a, int size, int value, char **args)
{
	int	*arr;

	arr = malloc((size + 1) * sizeof(int));
	if (!arr)
		ft_err(data, args, NULL);
	if (a->stack)
		arr = ft_memcpy(arr, a->stack, size);
	arr[size] = value;
	free(a->stack);
	a->stack = arr;
}
