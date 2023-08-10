/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:25:58 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/10 14:58:08 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_data *data)
{
	t_node	*node;
	int		tmp;
	int		tmp2;

	node = data->stack_a;
	if (!node || !node->next)
		return ;
	tmp = node->next->rank;
	tmp2 = node->next->value;
	node->next->rank = node->rank;
	node->next->value = node->value;
	node->rank = tmp;
	node->value = tmp2;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data)
{
	t_node	*node;
	int		tmp;
	int		tmp2;

	node = data->stack_b;
	if (!node || !node->next)
		return ;
	tmp = node->next->rank;
	tmp2 = node->next->value;
	node->next->rank = node->rank;
	node->next->value = node->value;
	node->rank = tmp;
	node->value = tmp2;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
{
	sb(data);
	sa(data);
	ft_putstr_fd("ss\n", 1);
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
	ft_putstr_fd("pa\n", 1);
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
	ft_putstr_fd("pb\n", 1);
}
