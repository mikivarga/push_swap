/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:51:11 by mvarga            #+#    #+#             */
/*   Updated: 2018/02/13 15:36:54 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void		sort_rev(long *a, long *b, ssize_t i)
{
	rotate_a(a, TRUE);
	rotate_a(a, TRUE);
	rotate_a(a, TRUE);
	i -= 3;
	while (i--)
		push_b(b, a, TRUE);
	if (!swap_swap(a, b, TRUE))
		swap_a(a, TRUE);
	if (b[2] < END)
	{
		reverse_rotate_rotate(a, b, TRUE);
		push_a(a, b, TRUE);
	}
	else
		reverse_rotate_a(a, TRUE);
	while (b[2] < END)
	{
		reverse_rotate_b(b, TRUE);
		push_a(a, b, TRUE);
	}
	push_a(a, b, TRUE);
	push_a(a, b, TRUE);
}

int						check_rev(long *a, long *b)
{
	ssize_t i;

	i = 0;
	if (b[0] != END)
		return (FALSE);
	while (a[i++] != END)
	{
		if (a[i] > a[i - 1] && a[i] != END)
			return (FALSE);
	}
	i = len_stack(a, END);
	if (i == 2)
		sort_two_steck_a(a);
	else if (i == 3)
		return (FALSE);
	else if (i > 1)
		sort_rev(a, b, i);
	return (TRUE);
}

static inline void		sort_a(long *a, long midl_a)
{
	if (a[0] == midl_a)
	{
		if (a[1] > midl_a)
			reverse_rotate_a(a, TRUE);
		else
			swap_a(a, TRUE);
	}
	else if (a[1] == midl_a)
	{
		if (a[0] > midl_a)
		{
			rotate_a(a, TRUE);
			swap_a(a, TRUE);
		}
	}
	else
	{
		if (a[0] > midl_a)
			rotate_a(a, TRUE);
		else
		{
			swap_a(a, TRUE);
			rotate_a(a, TRUE);
		}
	}
}

void					sort_steck_a(long *a, long *b, ssize_t len)
{
	long			midl_a;
	long			midl_b;
	ssize_t			cnt;

	cnt = len / 2;
	midl_a = quick_select(a, len, cnt);
	midl_b = quick_select(a, len, 1);
	while (cnt)
		if (a[0] < midl_a)
		{
			push_b(b, a, TRUE);
			if (b[0] < midl_b)
				rotate_b(b, TRUE);
			cnt--;
		}
		else
			rotate_a(a, TRUE);
	midl_a = quick_select(a, len, 1);
	sort_a(a, midl_a);
	cnt = len_stack(b, END);
	if (cnt == 2)
		sort_two_steck_b(a, b);
	else
		sort_three_steck_b(a, b, cnt);
}

void					sort_three(long *a, ssize_t len)
{
	long			midl;

	midl = quick_select(a, len, 1);
	if (a[0] == midl)
	{
		if (a[1] < a[2])
			swap_a(a, TRUE);
		else
			reverse_rotate_a(a, TRUE);
	}
	else if (a[1] == midl && a[0] > a[2])
	{
		rotate_a(a, TRUE);
		swap_a(a, TRUE);
	}
	else
	{
		if (a[0] < a[1])
			swap_a(a, TRUE);
		rotate_a(a, TRUE);
	}
}
