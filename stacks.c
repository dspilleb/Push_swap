/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:14:00 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/10 14:39:02 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int ac, char **av, t_data *data)
{
	t_node	*node;
	int		i;

	i = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
	node = NULL;
	while (av[++i])
	{
		if (!node)
		{
			data->stack_a = init_node(data, ft_atoi(av[i]));
			node = data->stack_a;
		}
		else
		{
			node_append(data, node, ft_atoi(av[i]));
			node = node->next;
		}
	}
}

t_node	*init_node(t_data *data, int val)
{
	t_node	*node;

	node = malloc(sizeof(struct node));
	node->next = NULL;
	node->prev = NULL;
	node->value = val;
	node->rank = -1;
	return (node);
}

void	node_append(t_data *data, t_node *node, int val)
{
	t_node	*append;

	if (!node)
		return ;
	append = init_node(data, val);
	append->prev = node;
	node->next = append;
}

t_node	*find_min(t_data *data)
{
	t_node	*ret;
	t_node	*node;
	int		min;

	ret = NULL;
	min = INT_MAX;
	node = data->stack_a;
	while (node)
	{
		if (node->value <= min && node->rank == -1)
		{
			min = node->value;
			ret = node;
		}
		node = node->next;
	}
	return (ret);
}

void	rank_stack(t_data *data)
{
	t_node	*node;
	int		count;
	int		flag;

	flag = 1;
	count = 0;
	while (flag)
	{
		node = find_min(data);
		if (!node)
			flag = 0;
		else
		{
			node->rank = count;
			count++;
		}
	}
}
