/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:39:00 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:40:09 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "./../libft/libft.h"

int		rotate_a(long *a, int flag)
{
	int		i;
	long	tmp;

	if (a[0] < END && a[1] < END)
	{
		i = 0;
		tmp = a[0];
		while (a[++i] != END)
			a[i - 1] = a[i];
		a[i - 1] = tmp;
		if (flag)
			ft_putstr("ra\n");
		return (TRUE);
	}
	return (FALSE);
}

int		rotate_b(long *b, int flag)
{
	int		i;
	long	tmp;

	if (b[0] < END && b[1] < END)
	{
		i = 0;
		tmp = b[0];
		while (b[++i] != END)
			b[i - 1] = b[i];
		b[i - 1] = tmp;
		if (flag)
			ft_putstr("rb\n");
		return (TRUE);
	}
	return (FALSE);
}

int		rotate_rotate(long *a, long *b, int flag)
{
	int		flag_a;
	int		flag_b;

	flag_a = rotate_a(a, FALSE);
	flag_b = rotate_b(b, FALSE);
	if (flag_a && flag_b)
	{
		if (flag)
			ft_putstr("rr\n");
		return (TRUE);
	}
	if (flag_a)
		rotate_a(a, FALSE);
	if (flag_b)
		rotate_b(b, FALSE);
	return (FALSE);
}
