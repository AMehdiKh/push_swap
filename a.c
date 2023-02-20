/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:08:26 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/20 18:11:09 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(void)
{
	return (0);
}
