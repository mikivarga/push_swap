/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:40:25 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:41:44 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "./../libft/libft.h"

int			swap_a(long *a, int flag)
{
	long	tmp;

	if (a[0] < END && a[1] < END)
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		if (flag)
			ft_putstr("sa\n");
		return (TRUE);
	}
	return (FALSE);
}

int			swap_b(long *b, int flag)
{
	long	tmp;

	if (b[0] < END && b[1] < END)
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
		if (flag)
			ft_putstr("sb\n");
		return (TRUE);
	}
	return (FALSE);
}

int			swap_swap(long *a, long *b, int flag)
{
	int		flag_a;
	int		flag_b;

	flag_a = swap_a(a, FALSE);
	flag_b = swap_b(b, FALSE);
	if (flag_a && flag_b)
	{
		if (flag)
			ft_putstr("ss\n");
		return (TRUE);
	}
	if (flag_a)
		swap_a(a, FALSE);
	if (flag_b)
		swap_b(b, FALSE);
	return (FALSE);
}

int			push_a(long *a, long *b, int flag)
{
	int		i;
	long	tmp;

	if (b[0] < END)
	{
		tmp = b[0];
		i = 0;
		while (b[++i] < END)
			b[i - 1] = b[i];
		b[i - 1] = END;
		i = 0;
		while (a[i++] < END)
			;
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = tmp;
		if (flag)
			ft_putstr("pa\n");
		return (TRUE);
	}
	return (FALSE);
}

int			push_b(long *b, long *a, int flag)
{
	int		i;
	long	tmp;

	if (a[0] < END)
	{
		tmp = a[0];
		i = 0;
		while (a[++i] < END)
			a[i - 1] = a[i];
		a[i - 1] = END;
		i = 0;
		while (b[i++] < END)
			;
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = tmp;
		if (flag)
			ft_putstr("pb\n");
		return (TRUE);
	}
	return (FALSE);
}
