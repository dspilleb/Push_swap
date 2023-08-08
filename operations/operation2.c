/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:31:20 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 15:22:15 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_data *data)
{
	t_node	*push;

	if (!data->stack_b)
		return ;
	push = init_node(data, data->stack_b->value);
	data->stack_b = data->stack_b->next;
	free(data->stack_b->prev);
	if (data->stack_a)
	{
		data->stack_a->prev = push;
		push->next = data->stack_a;
	}
	data->stack_a = push;
}

void	pb(t_data *data)
{
	t_node	*push;

	if (!data->stack_a)
		return ;
	push = init_node(data, data->stack_a->value);
	data->stack_a = data->stack_a->next;
	free(data->stack_a->prev);
	if (data->stack_b)
	{
		data->stack_b->prev = push;
		push->next = data->stack_b;
	}
	data->stack_b = push;
}
