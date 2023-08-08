/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:01:28 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/08 13:29:18 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "errno.h"
# include <stdio.h>

typedef struct node {
	int			value;
	struct node	*prev;
	struct node	*next;
}	t_node;
typedef struct data {
	t_node	*stack_a;
	t_node	*last_a;
	t_node	*stack_b;
	t_node	*last_b;
	int		status;
}	t_data;

void	init_stacks(int ac, char **av, t_data *data);
t_node	*init_node(t_data *data, int val);
t_node	*node_append(t_data *data, t_node *last, int val);
t_node	*init_empty_list(t_data *data, t_node *last, int val);
void	free_nodes(t_node *last);

int		only_int(char **av);
int		no_duplicate(char **av);
int		is_equal(char *s1, char *s2);
int		ft_atoi(const char *nptr);
void	check_all_args(int ac, char **av, t_data *data);

void	ft_putstr_fd(char *s, int fd);
void	failure_exit(t_data *data);
void	print_nodes(t_node *node);

#endif