/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:31:20 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 18:14:44 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_data *data)
{
	t_node	*node;
	t_node	*first;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	first = data->stack_a;
	data->stack_a = data->stack_a->next;
	data->stack_a->prev = NULL;
	node = first;
	while (node->next)
		node = node->next;
	node->next = first;
	node = first->prev;
	first->next = NULL; 
}

void	rb(t_data *data)
{
	t_node	*node;
	t_node	*first;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	first = data->stack_b;
	data->stack_b = data->stack_b->next;
	data->stack_b->prev = NULL;
	node = first;
	while (node->next)
		node = node->next;
	node->next = first;
	node = first->prev;
	first->next = NULL; 
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}

void	rra(t_data *data)
{
	t_node	*node;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	node = data->stack_a->next;
	while (node->next)
		node = node->next;
	node->prev->next = NULL;
	node->next = data->stack_a;
	data->stack_a->prev = node;
	data->stack_a = node;
}

void	rrb(t_data *data)
{
	t_node	*node;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	node = data->stack_b->next;
	while (node->next)
		node = node->next;
	node->prev->next = NULL;
	node->next = data->stack_b;
	data->stack_b->prev = node;
	data->stack_b = node;
}
