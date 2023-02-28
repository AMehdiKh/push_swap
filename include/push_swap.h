/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:56:01 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/28 16:06:50 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include "./LibFT/libft.h"

typedef struct s_stack
{
	int		*stack;
	int		size;
}	t_stack;

void	ft_check_args(t_stack *a, int ac, char **av);
long	ft_atol(t_stack *a, char **args, const char *s);
void	ft_add_back(t_stack *a, int size, int value, char **args);
void	ft_check_dup(t_stack *a, int man);
int		*ft_rank_stack(t_stack *a);
void	ft_rank(t_stack *a, int *ptr);

void	ft_sa(t_stack *a, int rule);
void	ft_sb(t_stack *b, int rule);
void	ft_ss(t_stack *a, t_stack *b, int rule);
void	ft_pa(t_stack *a, t_stack *b, int rule);
void	ft_pb(t_stack *a, t_stack *b, int rule);
void	ft_ra(t_stack *a, int rule);
void	ft_rb(t_stack *b, int rule);
void	ft_rr(t_stack *a, t_stack *b, int rule);
void	ft_rra(t_stack *a, int rule);
void	ft_rrb(t_stack *b, int rule);
void	ft_rrr(t_stack *a, t_stack *b, int rule);

void	ft_err(t_stack *a, char **args, char *str);
void	ft_clear(char **ptr);

void	ft_sort_small(t_stack *a, t_stack *b);
void	ft_range_sort(t_stack *a, t_stack *b, int range);
void	ft_push_to_b(t_stack *a, t_stack *b, int range);
int		ft_position(t_stack *ptr, int rank);

void	ft_read_rules(t_stack *a, t_stack *b);
int		ft_check_rules(t_stack *a, t_stack *b, char *str);
int		ft_sorted(t_stack *ptr);

#endif