/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:15:41 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:16:39 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./../instructions/instructions.h"
# include "./../libft/libft.h"

# define TRUE 1
# define FALSE 0
# define MAX 0
# define MIN 1
# define LEN 2
# define DISPLAY 0
# define COLOUR 1
# define MAX_I 2147483647L
# define MIN_I 2147483648L
# define END 30000000000L

ssize_t		len_stack(long *st, ssize_t block);
void		check_digits(char **argv, int *flags);
int			check(long *a, long *b);
int			ft_isspace(char c);
void		exec_instr(long *a, long *b, int *flags);
long		*save_input(char **ar, ssize_t *max_min_len);
int			check_input(long *a, ssize_t *max_min_len, ssize_t i);
int			build_stecks(long *a, long *b, char *instr, int *flags);
void		show(long *a, long *b, int *flags, char *instr);
void		show_instructions(void);

#endif
