/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:34:05 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/19 13:42:56 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(t_data *data, int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		data->str = ft_split(av[i], ' ');
		if (!data->str)
			ft_err(data, NULL);
		if (!*data->str)
			ft_err(data, "Error");
		j = -1;
		while (data->str[++j])
			ft_add_back(&data->a, ft_new(data, ft_atol(data, data->str[j])));
		ft_clear(&data->str);
		data->a_size += j;
	}
	check_dup(data);
}

long	ft_atol(t_data *data, const char *s)
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
		ft_err(data, "Error");
	return (result);
}

void	check_dup(t_data *data)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		sorted;
	int		pos;

	pos = -1;
	sorted = 1;
	stack = data->a;
	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value > tmp->value && sorted)
				sorted = 0;
			if (stack->value == tmp->value)
				ft_err(data, "Error");
			tmp = tmp->next;
		}
		stack->pos = ++pos;
		stack = stack->next;
	}
	stack->pos = ++pos;
	if (sorted)
	{
		ft_putendl_fd("The numbers are already sorted", 1);
		ft_stack_clear(&data->a);
		exit(EXIT_SUCCESS);
	}
}

void	ft_err(t_data *data, char *str)
{
	if (str)
		ft_putendl_fd("Error", 2);
	ft_stack_clear(&data->a);
	ft_clear(&data->str);
	exit(EXIT_FAILURE);
}

void	ft_clear(char ***ptr)
{
	int	i;

	if (*ptr)
	{
		i = 0;
		while (*(*ptr + i))
		{
			free(*(*ptr + i));
			++i;
		}
		free(*ptr);
		*ptr = NULL;
	}
}

void	check_dup(t_data *data)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		sorted;

	pos = -1;
	sorted = 1;
	stack = data->a;
	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value < tmp->value && sorted)
			sorted = 0;
			if (stack->value == tmp->value)
				ft_err(data, "Error");
			tmp = tmp->next;
		}
		stack->pos = ++pos;
		stack = stack->next;
	}
}
