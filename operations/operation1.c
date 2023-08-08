/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:25:58 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 17:34:13 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_data *data)
{
	t_node	*node; 
	int		tmp;

	node = data->stack_a;
	if (!node || !node->next)
		return ;
	tmp = node->next->value;
	node->next->value = node->value;
	node->value = tmp; 
}

void	sb(t_data *data)
{
	t_node	*node; 
	int		tmp;

	node = data->stack_b;
	if (!node || !node->next)
		return ;
	tmp = node->next->value;
	node->next->value = node->value;
	node->value = tmp; 
}

void	ss(t_data *data)
{
	sb(data);
	sa(data);
}

void	pa(t_data *data)
{
	t_node	*push;

	if (!data->stack_b)
		return ;
	push = data->stack_b;
	data->stack_b = data->stack_b->next;
	if (data->stack_b)
		data->stack_b->prev = NULL;
	if (data->stack_a)
		data->stack_a->prev = push;
	push->next = data->stack_a;
	data->stack_a = push;
}

void	pb(t_data *data)
{
	t_node	*push;

	if (!data->stack_a)
		return ;
	push = data->stack_a;
	data->stack_a = data->stack_a->next;
	if (data->stack_a)
		data->stack_a->prev = NULL;
	if (data->stack_b)
		data->stack_b->prev = push;
	push->next = data->stack_b;
	data->stack_b = push;
}
