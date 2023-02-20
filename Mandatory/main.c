/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/20 21:36:57 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data[1];
	t_stack	*tmp;

	if (ac < 2)
		return (0);
	ft_bzero(data, sizeof(t_data));
	ft_check_args(data, ac, av);
	if (stack->a_size )
		ft_sort_2(data);
	tmp = data->a;
	while(tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_rra(data, 1);
	printf("----------------\n");
	tmp = data->a;
	while(tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_stack_clear(&data->a);
 	return (0);
}

void	ft_sort_2(t_data *data)
{
	ft_sa(data, 1);
}

void	ft_sort_3(t_data *data)
{
	int	half;
	t_stack	*a;

	half = data->a_size / 2;
	a = ft_stack_which(data->a, half);

	if (ft_stack_which(data->a, half) <= half)
}
