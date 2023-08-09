/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:22:20 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/09 11:23:24 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	third = data->stack_a->next->next->value;
	if (first > second && first < third)
		sa(data);
	else if (first > second && second > third)
	{
		sa(data);
		rra(data);
	}
	else if (first < second && second > third)
	{
		sa(data);
		ra(data);
	}
	else if (first > second && first > third)
		ra(data);
	else if (first < second && second > third)
		rra(data);

}

void	sort_two(t_data *data)
{
	int	first;
	int	second;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	if (first > second)
		sa(data);
}



void	test_sort(t_data *data)
{
	t_node	*stop;
	t_node	*node;
	int		i;
	int		value;
	unsigned char byte;

	i = 0;
	while (i < 32)
	{
		node = data->stack_a;
		stop = NULL;
		while (node && node->next && stop != node)
		{
			value = node->rank;
			byte = value >> (i) & 1;
			if (byte == 0)
				pb(data);
			else
			{
				if (!stop)
					stop = node;
				ra(data);
			}
			node = data->stack_a;
		}
		while (data->stack_b)
			pa(data);
		i ++;
	}
}
