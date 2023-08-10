/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:22:20 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/10 21:41:11 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->rank;
	second = data->stack_a->next->rank;
	third = data->stack_a->next->next->rank;
	if (first > second && first < third && second < third)
		sa(data);
	else if (first > second && first > third && second > third)
	{
		sa(data);
		rra(data);
	}
	else if (first < second && first < third && second > third)
	{
		sa(data);
		ra(data);
	}
	else if (first > second && first > third && second < third)
		ra(data);
	else if (first < second && first > third && second > third)
		rra(data);
	else
		return ;
}

void	sort_five(t_data *data)
{
	if (is_sorted(data))
		return ;
	pb(data);
	sort_four(data);
	if (data->stack_b->rank == 0)
		pa(data);
	else if (data->stack_b->rank == 1)
		psa(data);
	else if (data->stack_b->rank == 2)
	{
		ra(data);
		pa(data);
		sa(data);
		rra(data);
	}
	else if (data->stack_b->rank == 3)
	{
		rra(data);
		pa(data);
		ra(data);
		ra(data);
	}
	else
		pra(data);
}

void	sort_four(t_data *data)
{
	t_node	*node;
	int		pos;

	if (is_sorted(data))
		return ;
	pb(data);
	sort_three(data);
	node = data->stack_a;
	pos = 0;
	while (node && node->rank < data->stack_b->rank)
	{
		pos++;
		node = node->next;
	}
	if (pos == 0)
		pa(data);
	else if (pos == 1)
		psa(data);
	else
		sort_four2(data, pos);
}

void	sort_four2(t_data *data, int pos)
{
	if (pos == 2)
	{			
		rra(data);
		pa(data);
		ra(data);
		ra(data);
	}
	else
		pra(data);
}

void	radix_sort(t_data *data)
{
	t_node	*stop;
	t_node	*node;
	int		i;

	i = 0;
	while (!is_sorted(data))
	{
		node = data->stack_a;
		stop = NULL;
		while (node && node->next && stop != node)
		{
			if ((node->rank >> (i) & 1) == 0)
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
