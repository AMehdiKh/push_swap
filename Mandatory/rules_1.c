/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:25:50 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/18 21:43:35 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data *data, int rule)
{
	t_stack	*tmp_a;

	if (data->a_size < 2)
		return ;
	tmp_a = data->a->next;
	data->a->next = data->a->next->next;
	ft_add_front(&data->a, tmp_a);
	if (rule)
		ft_putendl_fd("sa", 1);
}

void	ft_sb(t_data *data, int rule)
{
	t_stack	*tmp_b;

	if (data->b_size < 2)
		return ;
	tmp_b = data->b->next;
	data->b->next = data->b->next->next;
	ft_add_front(&data->b, tmp_b);
	if (rule)
		ft_putendl_fd("sb", 1);
}

void	ft_ss(t_data *data)
{
	ft_sa(data, 0);
	ft_sb(data, 0);
	ft_putendl_fd("ss", 1);
}

void	ft_pa(t_data *data)
{
	t_stack	*tmp_b;

	if (!data->b_size)
		return ;
	tmp_b = data->b;
	data->b = data->b->next;
	ft_add_front(&data->a, tmp_b);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_data *data)
{
	t_stack	*tmp_a;

	if (!data->a_size)
		return ;
	tmp_a = data->a;
	data->a = data->a->next;
	ft_add_front(&data->b, tmp_a);
	ft_putendl_fd("pb", 1);
}
