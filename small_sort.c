/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:22:20 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 19:07:40 by dspilleb         ###   ########.fr       */
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

