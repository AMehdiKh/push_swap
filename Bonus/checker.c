/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:34:39 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/25 06:29:23 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a[1];
	t_stack	b[1];

	if (ac < 1)
		return (0);
	ft_bzero(a, sizeof(t_stack));
	ft_check_args(a, ac, av);
	b->size = 0;
	b->stack = malloc(a->size * sizeof(int));
	if (!b->stack)
		ft_err(a, NULL, NULL);
	ft_read();
	free(a->stack);
	free(b->stack);
	return (0);
}

void	ft_read(void)
{
	char	*str;
	int		i;

	str = get_next_line(0);
	while (str)
	{
		if (ft_check_rules(str) == -1)
		{
			ft_putendl("Error", 2);
			free (str);
			free(a->stack);
			free(b->stack);
			exit(EXIT_FAILURE);
		}
		free(str);
		str = get_next_line(0);
	}
	if (ft_sorted(a) && !b->size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	ft_check_rules(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp("sa\n", str, 3)
		ft_sa(a, 0);
	else if (!ft_strncmp("sb\n", str, 3)
		ft_sb(b, 0);
	else if (!ft_strncmp("ss\n", str, 3)
		ft_ss(a, b, 0);
	else if (!ft_strncmp("ra\n", str, 3)
		ft_ra(a, 0);
	else if (!ft_strncmp("rb\n", str, 3)
		ft_rb(b, 0);
	else if (!ft_strncmp("rr\n", str, 3)
		ft_rr(a, b, 0);
	else if (!ft_strncmp("pa\n", str, 3)
		ft_pa(a, b, 0);
	else if (!ft_strncmp("pb\n", str, 3)
		ft_pb(a, b, 0);
	else if (!ft_strncmp("rra\n", str, 4)
		ft_rra(a, 0);
	else if (!ft_strncmp("rrb\n", str, 4)
		ft_rrb(a, 0);
	else if (!ft_strncmp("rrr\n", str, 4)
		ft_rrr(a, b, 0);
	else
		return (-1);
	return (0);
}

int	ft_sorted(t_stack *ptr)
{
	int	i;

	i = 0;
	while (++i < ptr->size)
		if (ptr->stack[i - 1] > ptr->stack[i])
			return (0);
	return (1);
}
