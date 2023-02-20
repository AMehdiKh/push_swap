/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/20 18:06:26 by ael-khel         ###   ########.fr       */
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

t_stack	*ft_stack_which(t_stack *stack, int pos)
{
	if (!stack)
		return (NULL);
	while (stack->next && pos--)
		stack = stack->next;
	return (stack);
}

void	sort_array(t_data *data)
{
	int	i;
	int	j;
	int	min_index;
	int	*ptr;

	ptr = malloc((a->size + 1) * sizeof(int));
	if (!ptr)
		ft_err(data, NULL, NULL);
	i = 0;
	while (i < a->size)
		ptr[i] = a->stack[i];
	i = -1;
	while (++i < data->a_size)
	{
		min_index = i;
		j = i;
		while (++j < data->a_size)
			if (ptr[j] < ptr[min_index])
				min_index = j;
		j = ptr[i];
		ptr[i] = ptr[min_index];
		ptr[min_index] = j;
		ft_rank_list(data, ptr[i], i);
	}
	free(ptr);
}
