/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:37:51 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:38:38 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "./../libft/libft.h"

int		reverse_rotate_a(long *a, int flag)
{
	int		i;
	long	tmp;

	if (a[0] < END && a[1] < END)
	{
		i = 0;
		while (a[++i] < END)
			;
		tmp = a[--i];
		a[i--] = END;
		while (i > 0)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = a[i];
		a[i] = tmp;
		if (flag)
			ft_putstr("rra\n");
		return (TRUE);
	}
	return (FALSE);
}

int		reverse_rotate_b(long *b, int flag)
{
	int		i;
	long	tmp;

	if (b[0] < END && b[1] < END)
	{
		i = 0;
		while (b[++i] < END)
			;
		tmp = b[--i];
		b[i--] = END;
		while (i > 0)
		{
			b[i + 1] = b[i];
			i--;
		}
		b[i + 1] = b[i];
		b[i] = tmp;
		if (flag)
			ft_putstr("rrb\n");
		return (TRUE);
	}
	return (FALSE);
}

int		reverse_rotate_rotate(long *a, long *b, int flag)
{
	int		flag_a;
	int		flag_b;

	flag_a = reverse_rotate_a(a, FALSE);
	flag_b = reverse_rotate_b(b, FALSE);
	if (flag_a && flag_b)
	{
		if (flag)
			ft_putstr("rrr\n");
		return (TRUE);
	}
	if (flag_a)
		reverse_rotate_a(a, FALSE);
	if (flag_b)
		reverse_rotate_b(b, FALSE);
	return (FALSE);
}
