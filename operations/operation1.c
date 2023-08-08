/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:25:58 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 14:58:25 by dspilleb         ###   ########.fr       */
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
