/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:25:50 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/17 11:05:49 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data *data, int rule)
{
	t_stack	*tmp_a;

	tmp_a = data->a;
	if (data->size_a < 2)
		return ;
	data->a = data->a->next;
	tmp_a->next = data->a->next;
	data->a->next = tmp_a;
	if (rule)
		ft_putendl_fd("sa", 1);
}

void	ft_sb(t_data *data, int rule)
{
	t_stack	*tmp_b;

	tmp_b = data->b;
	if (data->size_b < 2)
		return ;
	data->b = data->b->next;
	tmp_b->next = data->b->next;
	data->b->next = tmp_b;
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

	tmp_b = data->b;
	if (!data->size_b)
		return ;
	data->b = data->b->next;
	tmp_b->next = data->a;
	data->a = tmp_b;
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_data *data)
{
	t_stack	*tmp_a;

	tmp_a = data->a;
	if (!data->size_a)
		return ;
	data->a = data->a->next;
	tmp_a->next = data->b;
	data->b = tmp_a;
	ft_putendl_fd("pb", 1);
}

void	ft_ra(t_data *data, int rule)
{
	t_stack	*tmp_a;

	tmp_a = data->a;
	if (data->size_a < 3)
		return ;
	data->a = data->a->next;
	ft_add_back(&data->a, tmp_a);
	if (rule)
		ft_putendl_fd("ra", 1);
}

void	ft_rb(t_data *data, int rule)
{
	t_stack	*tmp_b;

	tmp_b = data->b;
	if (data->size_b < 3)
		return ;
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

	tmp_a = data->a;
	if (data->size_a < 3)
		return ;
	ft_add_front(&data->a, ft_stack_last(tmp_a));
	while (tmp_a->next->next)
		tmp_a = tmp_a->next;
	tmp_a->next = NULL;
	if (rule)
		ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_data *data, int rule)
{
	t_stack	*tmp_b;

	tmp_b = data->b;
	if (data->size_b < 3)
		return ;
	ft_add_front(&data->b, ft_stack_last(tmp_b));
	while (tmp_b->next->next)
		tmp_b = tmp_b->next;
	tmp_b->next = NULL;
	if (rule)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_data *data)
{
	ft_rra(data, 0);
	ft_rrb(data, 0);
	ft_putendl_fd("rrb", 1);
}
