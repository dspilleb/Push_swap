/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:00:22 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/05 17:48:57 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	errno = 0;
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	if (only_int(av) || no_duplicate(av))
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}