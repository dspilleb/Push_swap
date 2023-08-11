/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:00:22 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/11 11:24:35 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_data *data, int ac)
{
	if (ac == 3)
	{
		if (data->stack_a->rank > data->stack_a->next->rank)
			sa(data);
	}
	else if (ac == 4)
		sort_three(data);
	else if (ac == 5)
		sort_four(data);
	else if (ac == 6)
		sort_five(data);
	else
		radix_sort(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	errno = 0;
	check_all_args(av, &data);
	init_stacks(av, &data);
	rank_stack(&data);
	choose_sort(&data, ac);
	free_nodes(data.stack_a);
	return (0);
}
