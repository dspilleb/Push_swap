/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:14:00 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 13:38:25 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int ac, char **av, t_data *data)
{
	t_node	*node;
	int		i;

	i = 0;
	data->stack_a = NULL;
	while (av[++i])
		data->stack_a = node_append(data, data->stack_a, ft_atoi(av[i]));
}

t_node	*init_node(t_data *data, int val)
{
	t_node	*node;

	node = malloc(sizeof(struct node));
	node->next = NULL;
	node->prev = NULL;
	node->value = val;
}

t_node	*node_append(t_data *data, t_node *last, int val)
{
	t_node	*append;

	if (!last)
		return (init_empty_list(data, last, val));
	append = init_node(data, val);
	append->prev = last;
	append->next = last->next;
	last->next = append;
	last = append;
	return (last);
}


t_node	*init_empty_list(t_data *data, t_node *last, int val)
{
	t_node	*node;

	if (last)
		return (last);
	last = malloc(sizeof(struct node));
	last->next = last;
	last->prev = NULL;
	last->value = val;
	return (last);
}
