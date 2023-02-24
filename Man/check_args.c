/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:34:05 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/24 07:52:46 by ael-khel         ###   ########.fr       */
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
		ft_clear(args);
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

void	ft_add_back(t_stack *a, int size, int value, char **args)
{
	int	*arr;

	arr = ft_calloc(size + 1, sizeof(int));
	if (!arr)
		ft_err(a, args, NULL);
	arr = ft_memcpy(arr, a->stack, size * sizeof(int));
	arr[size] = value;
	free(a->stack);
	a->stack = arr;
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
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->stack[i] > a->stack[j] && sorted)
				sorted = 0;
			if (a->stack[i] == a->stack[j])
				ft_err(a, NULL, "Error");
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

void	ft_rank_stack(t_stack *a)
{
	int	i;
	int	j;
	int	min;
	int	*ptr;

	ptr = malloc(a->size * sizeof(int));
	if (!ptr)
		ft_err(a, NULL, NULL);
	ptr = ft_memcpy(ptr, a->stack, a->size * sizeof(int));
	i = -1;
	while (++i < a->size)
	{
		min = i;
		j = i;
		while (++j < a->size)
			if (ptr[min] > ptr[j])
				min = j;
		j = ptr[i];
		ptr[i] = ptr[min];
		ptr[min] = j;
		ft_rank(a, ptr[i], i);
	}
	free(ptr);
}
