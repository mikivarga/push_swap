/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:36:31 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:37:30 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# define TRUE 1
# define FALSE 0
# define END 30000000000L

int		swap_a(long *a, int flag);
int		swap_b(long *b, int flag);
int		swap_swap(long *a, long *b, int flag);
int		push_a(long *a, long *b, int flag);
int		push_b(long *b, long *a, int flag);
int		rotate_a(long *a, int flag);
int		rotate_b(long *b, int flag);
int		rotate_rotate(long *a, long *b, int flag);
int		reverse_rotate_a(long *a, int flag);
int		reverse_rotate_b(long *b, int flag);
int		reverse_rotate_rotate(long *a, long *b, int falg);

#endif
