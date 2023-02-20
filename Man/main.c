/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/20 23:57:43 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a[1];
	t_stack	b[1];
	int i;
	if (ac < 2)
		return (0);
	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));

	ft_check_args(a, b, ac, av);
	i = 0;
	while(i < a->size)
	{
		printf("%d\n", a->stack[i++]);
	}
	ft_pb(a, b);
	printf("----------------\n");
	i = 0;
	while(i < a->size)
		printf("%d\n", a->stack[i++]);
	free(a->stack);
	free(b->stack);
 	return (0);
}

// void	ft_sort_2(t_data *data)
// {
// 	ft_sa(data, 1);
// }

// void	ft_sort_3(t_data *data)
// {
// 	int	half;
// 	t_stack	*a;

// 	half = data->a_size / 2;
// 	a = ft_stack_which(data->a, half);

// 	if (ft_stack_which(data->a, half) <= half)
// }

// t_stack	*ft_stack_which(t_stack *stack, int pos)
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next && pos--)
// 		stack = stack->next;
// 	return (stack);
// }
