/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_steck_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:16:47 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 16:18:13 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				sort_two_steck_b(long *a, long *b)
{
	if (b[0] < b[1])
		swap_b(b, TRUE);
	push_a(a, b, TRUE);
	push_a(a, b, TRUE);
}

static inline void	b0_equal_midl_b(long *a, long *b, long midl_b)
{
	if (b[1] > midl_b)
	{
		swap_b(b, TRUE);
		push_a(a, b, TRUE);
		push_a(a, b, TRUE);
		push_a(a, b, TRUE);
	}
	else
	{
		push_a(a, b, TRUE);
		swap_b(b, TRUE);
		push_a(a, b, TRUE);
		swap_a(a, TRUE);
		push_a(a, b, TRUE);
	}
}

static inline void	b1_equal_midl_b(long *a, long *b, long midl_b)
{
	if (b[0] > midl_b)
	{
		push_a(a, b, TRUE);
		push_a(a, b, TRUE);
		push_a(a, b, TRUE);
	}
	else
	{
		swap_b(b, TRUE);
		push_a(a, b, TRUE);
		swap_b(b, TRUE);
		push_a(a, b, TRUE);
		swap_a(a, TRUE);
		push_a(a, b, TRUE);
	}
}

static inline void	b2_equal_midl_b(long *a, long *b, long midl_b)
{
	if (b[0] > midl_b)
	{
		push_a(a, b, TRUE);
		sort_two_steck_b(a, b);
	}
	else
	{
		swap_b(b, TRUE);
		push_a(a, b, TRUE);
		sort_two_steck_b(a, b);
	}
}

void				sort_three_steck_b(long *a, long *b, ssize_t len)
{
	long	midl_b;

	midl_b = quick_select(b, len, 1);
	if (b[0] == midl_b)
		b0_equal_midl_b(a, b, midl_b);
	else if (b[1] == midl_b)
		b1_equal_midl_b(a, b, midl_b);
	else
		b2_equal_midl_b(a, b, midl_b);
}
