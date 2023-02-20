/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:56:01 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/20 19:03:38 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "../LibFT/libft.h"

typedef struct s_stack
{
	int		*stack;
	int		size;
}	t_stack;


void	ft_check_args(t_data *data, int ac, char **av);
long	ft_atol(t_data *data, const char *s);
void	check_dup(t_data *data);

t_stack	*ft_new(t_data *data, int value);
void	ft_add_front(t_stack **head, t_stack *new);
void	ft_add_back(t_stack **head, t_stack *new);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_clear(t_stack **head);
int		ft_stacksize(t_stack *stack);

void	ft_sa(t_data *data, int rule);
void	ft_sb(t_data *data, int rule);
void	ft_ss(t_data *data);
void	ft_pa(t_data *data);
void	ft_pb(t_data *data);
void	ft_ra(t_data *data, int rule);
void	ft_rb(t_data *data, int rule);
void	ft_rr(t_data *data);
void	ft_rra(t_data *data, int rule);
void	ft_rrb(t_data *data, int rule);
void	ft_rrr(t_data *data);

void	ft_err(t_data *data, char *str);
void	ft_clear(char ***ptr);
void	ft_sort_2(t_data *data);
t_stack	*ft_stack_which(t_stack *stack, int pos);

#endif