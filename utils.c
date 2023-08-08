/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:00 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 15:21:35 by dspilleb         ###   ########.fr       */
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

void	print_nodes(t_data *data)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = data->stack_a;
	node_b = data->stack_b;
	printf("command\n");
	while (node_a || node_b)
	{
		if (node_a)
		{
			printf("%d ", node_a->value);
			node_a = node_a->next;
		}
		if (node_b)
		{
			printf("%d", node_b->value);
			node_b = node_b->next;
		}
		printf("\n");
	}
	printf("_ _\n");
	printf("a b\n");
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

void	failure_exit(t_data *data)
{
	free_nodes(data->stack_a);
	free_nodes(data->stack_b);
	exit(1);
}
