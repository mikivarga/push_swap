/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:01:01 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 16:43:12 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./../instructions/instructions.h"
# include "./../libft/libft.h"
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define MAX 0
# define MIN 1
# define LEN 2
# define MAX_I 2147483647L
# define MIN_I 2147483648L
# define END 30000000000L

long	*save_input(char **ar, ssize_t *max_min_len);
int		check_input(long *a, ssize_t *max_min_len, ssize_t i);
long	quick_select(long *ar, ssize_t len, ssize_t k);
ssize_t	len_stack(long *st, ssize_t block);
int		check_rev(long *a, long *b);
void	sort_three(long *a, ssize_t len);
void	sort_steck_a(long *a, long *b, ssize_t len);
void	separation_steck_a(long *a, long *b, long block, int flag);
void	sort_two_steck_a(long *a);
void	sort_three_steck_a(long *a, ssize_t len);
void	separation_steck_b
(long *a, long *b, long block_a, ssize_t *cnt_b);
void	sort_two_steck_b(long *a, long *b);
void	sort_three_steck_b(long *a, long *b, ssize_t len);

#endif
