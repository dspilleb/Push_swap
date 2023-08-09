/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:01:28 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/09 11:21:41 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "errno.h"
# include <stdio.h>
# include <limits.h>

typedef struct node {
	int			value;
	int			rank;
	struct node	*prev;
	struct node	*next;
}	t_node;
typedef struct data {
	t_node	*stack_a;
	t_node	*stack_b;
	int		status;
}	t_data;

void	init_stacks(int ac, char **av, t_data *data);
t_node	*init_node(t_data *data, int val);
void	node_append(t_data *data, t_node *node, int val);
void	rank_stack(t_data *data);
t_node	*find_min(t_data *data);

int		only_int(char **av);
int		no_duplicate(char **av);
int		is_equal(char *s1, char *s2);
int		ft_atoi(const char *nptr);
void	check_all_args(int ac, char **av, t_data *data);

void	ft_putstr_fd(char *s, int fd);
void	failure_exit(t_data *data);
void	print_nodes(t_data *data);
void	free_nodes(t_node *last);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pb(t_data *data);
void	pa(t_data *data);

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);

void	rrr(t_data *data);

void	sort_three(t_data *data);
void	sort_two(t_data *data);
void	test_sort(t_data *data);
#endif