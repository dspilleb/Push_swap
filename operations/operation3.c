/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:59:40 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/10 21:25:36 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	ft_putstr_fd("rrr\n", 1);
}

void	psa(t_data *data)
{
	pa(data);
	sa(data);
}

void	pra(t_data *data)
{
	pa(data);
	ra(data);
}
