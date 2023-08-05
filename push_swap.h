/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:01:28 by dspilleb          #+#    #+#             */
/*   Updated: 2023/08/05 17:51:52 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./My_Libft/libft.h"
# include "errno.h"

int	only_int(char **av);
int	no_duplicate(char **av);
int is_equal(char *s1, char *s2);

#endif