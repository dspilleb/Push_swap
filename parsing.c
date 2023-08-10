/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:34:29 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/09 13:27:25 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			if (!(av[j][i] >= '0' && av[j][i] <= '9' || av[j][i] == '-'))
				return (EXIT_FAILURE);
			if (av[j][i] == '-' && (i != 0 || !av[j][i + 1]))
				return (EXIT_FAILURE);
		}
		if (i == 0)
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

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	number;

	number = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10;
		number = number + nptr[i] - 48;
		i++;
		if (number * sign > 2147483647 || number * sign < -2147483648)
			errno = 22;
	}
	return (number * sign);
}

void	check_all_args(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	if (only_int(av) || no_duplicate(av))
		failure_exit(data);
	while (av[++i] && errno == 0)
		ft_atoi(av[i]);
	if (errno != 0)
		failure_exit(data);
}
