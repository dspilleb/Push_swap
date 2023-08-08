/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:14:00 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 18:39:02 by dspilleb         ###   ########.fr       */
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