/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:13:00 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 13:32:23 by dspilleb         ###   ########.fr       */
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

void	print_nodes(t_node *last)
{
	t_node	*node;

	node = last->next;
	while (node != last)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("%d", node->value);
}

void	free_nodes(t_node *last)
{
	t_node	*node;

	if (!last)
		return ;
	node = last->next;
	while (node != last)
	{
		free(node);
		node = node->next;
	}
	free(node);
}

void	failure_exit(t_data *data)
{
	free_nodes(data->stack_a);
	free_nodes(data->stack_b);
	exit(1);
}
