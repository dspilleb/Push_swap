/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:00 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/10 14:39:07 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i])
			write(fd, &s[i], 1);
}

void	free_nodes(t_node *node)
{
	t_node	*next;

	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

int	is_sorted(t_data *data)
{
	t_node	*node;
	int		ret;

	ret = 1;
	node = data->stack_a;
	while (node->next)
	{
		if (node->rank > node->next->rank)
			ret = 0;
		node = node->next;
	}
	return (ret);
}

void	failure_exit(t_data *data)
{
	free_nodes(data->stack_a);
	free_nodes(data->stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
