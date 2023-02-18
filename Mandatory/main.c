/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/18 21:43:47 by ael-khel         ###   ########.fr       */
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
	data->a_size = ft_stacksize(data->a);
	tmp = data->a;
	while(tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_rra(data, 1);
	printf("----------------\n");
	while(data->a)
	{
		printf("%d\n", data->a->nbr);
		data->a = data->a->next;
	}
 	return (0);
}
