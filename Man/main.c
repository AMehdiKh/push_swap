/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:55:24 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/21 21:31:44 by ael-khel         ###   ########.fr       */
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
	b->stack = malloc(a->size * sizeof(int));
	if (!b->stack)
		ft_err(a, NULL, NULL);
	// printf("sizo  %d\n", a->size);
	// i = 0;
	// while(i < a->size)
	// {
	// 	printf("%d\n", a->stack[i++]);
	// }
	ft_sort(a, b);
	// printf("----------------\n");
	// i = 0;
	// while(i < a->size)
	// 	printf("%d\n", a->stack[i++]);
	free(a->stack);
	free(b->stack);
 	return (0);
}

int	ft_index(t_stack *ptr, int rank)
{
	int	i;

	i = 0;
	while (i < ptr->size)
	{
		if (ptr->stack[i] == rank)
			return (i);
		++i;
	}
	return (-1);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->size)
	{
		if (ft_index(a, i) <= a->size / 2 && ft_index(a, i) != -1)
		{
			while (ft_index(a, i) != 0 && ft_index(a, i) != -1)
				ft_ra(a, 1);
		}
		else
		{
			while (ft_index(a, i) != 0 && ft_index(a, i) != -1)
				ft_rra(a, 1);
		}
		ft_pb(a, b);
		++i;
	}
	while (b->size)
		ft_pa(a, b);
}

// void	ft_khra(t_stack *a)
// {
// 	int	i;

// 	i = 0;
// 	printf("\n##################\n");
// 	while(i < a->size)
// 	{
// 		printf("\na ->%d\n", a->stack[i++]);
// 	}
// 	printf("\nsize ->%d\n", a->size);

// 	printf("\n##################\n");
// }
// void	ft_sort_2(t_data *data)
// {
// 	ft_sa(data, 1);
// }

void	ft_sort_3(t_stack *a)
{
	if (ft_index(a, 2) == 1)
		ft_sa(a, 1);
	if (ft_ft_index(a, 2) == 0)
		ft_ra(a, 1);
	if (ft_ft_index(a, 0) == 1)
		ft_sa(a, 1);
}

// t_stack	*ft_stack_which(t_stack *stack, int pos)
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next && pos--)
// 		stack = stack->next;
// 	return (stack);
// }
