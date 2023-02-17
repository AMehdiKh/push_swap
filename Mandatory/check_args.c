/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:34:05 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/17 10:35:47 by ael-khel         ###   ########.fr       */
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
	}
	ft_clear(data->str);
	if (check_dup(data, data->a))
	{
		ft_stack_clear(&data->a);
		printf ("OK\n");
		exit(EXIT_SUCCESS);
	}
	printf ("OK\n");
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

int	check_dup(t_data *data, t_stack *stack)
{
	int		sorted;
	t_stack	*tmp;

	sorted = 1;
	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr > tmp->nbr)
				sorted = 0;
			if (stack->nbr == tmp->nbr)
				ft_err(data, "Error");
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (sorted);
}

void	ft_err(t_data *data, char *str)
{
	if (str)
		ft_putendl_fd("Error", 2);
	ft_stack_clear(&data->a);
	ft_clear(data->str);
	exit(EXIT_FAILURE);
}

void	ft_clear(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
		while (ptr[i])
			++i;
	while (i--)
		free(ptr[i]);
	free(ptr);
}
