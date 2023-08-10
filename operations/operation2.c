/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:31:20 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/10 10:21:05 by dspilleb         ###   ########.fr       */
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
	data->stack_a = first->next;
	first->prev = NULL;
	node = data->stack_a;
	while (node->next)
		node = node->next;
	node->next = first;
	node->next->prev = node; 
	first->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data)
{
	t_node	*node;
	t_node	*first;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	first = data->stack_b;
	data->stack_b = first->next;
	first->prev = NULL;
	node = data->stack_b;
	while (node->next)
		node = node->next;
	node->next = first;
	node->next->prev = node; 
	first->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_data *data)
{
	t_node	*first;
	t_node	*node;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	node = data->stack_a;
	first = data->stack_a;
	while (node->next)
		node = node->next;
	node->prev->next = NULL;
	node->prev = NULL;
	node->next = first;
	first->prev = node;
	data->stack_a = node;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data)
{
	t_node	*first;
	t_node	*node;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	node = data->stack_b;
	first = data->stack_b;
	while (node->next)
		node = node->next;
	node->prev->next = NULL;
	node->prev = NULL;
	node->next = first;
	first->prev = node;
	data->stack_b = node;
	ft_putstr_fd("rrb\n", 1);
}
