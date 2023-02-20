/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:53:12 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/19 07:14:24 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new(t_data *data, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_err(data, NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_add_front(t_stack **head, t_stack *new)
{
	new->next = *head;
	*head = new;
}

void	ft_add_back(t_stack **head, t_stack *new)
{
	t_stack	*tmp_head;

	tmp_head = ft_stack_last(*head);
	if (*head)
	{
		new->next = NULL;
		tmp_head->next = new;
	}
	else
		*head = new;
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stack_clear(t_stack **head)
{
	t_stack	*freed;

	while (*head)
	{
		freed = *head;
		*head = (*head)->next;
		free(freed);
	}
}

int	ft_stacksize(t_stack *stack)
{
	if (!stack)
		return (0);
	return (ft_stacksize(stack->next) + 1);
}
