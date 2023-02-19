/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:11:17 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/19 03:13:04 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_data *data, int rule)
{
	t_stack	*tmp_a;

	if (data->a_size < 3)
		return ;
	tmp_a = data->a;
	data->a = data->a->next;
	ft_add_back(&data->a, tmp_a);
	if (rule)
		ft_putendl_fd("ra", 1);
}

void	ft_rb(t_data *data, int rule)
{
	t_stack	*tmp_b;

	if (data->b_size < 3)
		return ;
	tmp_b = data->b;
	data->b = data->b->next;
	ft_add_back(&data->b, tmp_b);
	if (rule)
		ft_putendl_fd("rb", 1);
}

void	ft_rr(t_data *data)
{
	ft_ra(data, 0);
	ft_rb(data, 0);
	ft_putendl_fd("rr", 1);
}

void	ft_rra(t_data *data, int rule)
{
	t_stack	*tmp_a;

	if (data->a_size < 3)
		return ;
	tmp_a = data->a;
	while (tmp_a->next->next)
		tmp_a = tmp_a->next;
	ft_add_front(&data->a, tmp_a->next);
	tmp_a->next = NULL;
	if (rule)
		ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_data *data, int rule)
{
	t_stack	*tmp_b;

	if (data->b_size < 3)
		return ;
	tmp_b = data->b;
	while (tmp_b->next->next)
		tmp_b = tmp_b->next;
	ft_add_front(&data->b, tmp_b->next);
	tmp_b->next = NULL;
	if (rule)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_data *data)
{
	ft_rra(data, 0);
	ft_rrb(data, 0);
	ft_putendl_fd("rrr", 1);
}
