/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:00:22 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 18:43:25 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac < 2)
		return (0);
	errno = 0;
	check_all_args(ac, av, &data);
	init_stacks(ac, av, &data);
	if (ac == 4)
		sort_three(&data);
	if (ac == 3)
		sort_two(&data);
	print_nodes(&data);
	free_nodes(data.stack_a);
	return (0);
}
