/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:34:29 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/05 17:53:09 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	only_int(char **av)
{
	int	j;
	int	i;

	j = 0;
	while (av[++j])
	{
		i = -1;
		while (av[j][++i])
			if (!ft_isdigit(av[j][i]))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	no_duplicate(char **av)
{
	int		j;
	int		i;

	j = 0;
	while (av[++j])
	{
		i = j;
		while (av[++i])
			if (is_equal(av[i], av[j]) == 0)
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
