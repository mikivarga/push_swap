/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:49:33 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:50:10 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(long *ar, ssize_t a, ssize_t b)
{
	long	tmp;

	tmp = ar[a];
	ar[a] = ar[b];
	ar[b] = tmp;
}

static long	qselect(long *a, ssize_t len, int k)
{
	ssize_t	i;
	ssize_t	st;

	st = 0;
	i = 0;
	while (i < (len - 1))
	{
		if (a[i] > a[len - 1])
		{
			i++;
			continue;
		}
		ft_swap(a, i, st);
		i++;
		st++;
	}
	ft_swap(a, len - 1, st);
	if (k == st)
		return (a[st]);
	else if (st > k)
		return (qselect(a, st, k));
	else
		return (qselect(a + st, len - st, k - st));
}

long		quick_select(long *ar, ssize_t len, ssize_t k)
{
	ssize_t	i;
	long	res;
	long	*tmp;

	tmp = (long *)malloc(sizeof(long) * len);
	i = 0;
	while (i < len)
	{
		tmp[i] = ar[i];
		i++;
	}
	res = qselect(tmp, len, k);
	free(tmp);
	return (res);
}
