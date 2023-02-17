/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:56:01 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/17 07:54:20 by ael-khel         ###   ########.fr       */
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
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	char	**str;
	int		a_size;
	int		b_size;
}	t_data;

void	ft_check_args(t_data *data, int ac, char **av);
long	ft_atol(t_data *data, const char *s);
int		check_dup(t_data *data, t_stack *stack);

t_stack	*ft_new(t_data *data, int nbr);
void	ft_add_front(t_stack **head, t_stack *new);
void	ft_add_back(t_stack **head, t_stack *new);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_clear(t_stack **head);

void	ft_err(t_data *data, char *str);
void	ft_clear(char **ptr);

#endif