/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:05:16 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:49:00 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long		*init_steck_b(ssize_t size)
{
	long		*b;
	ssize_t		i;

	b = (long *)malloc(sizeof(long) * (size + 1));
	i = -1;
	while (++i < size)
		b[i] = END;
	b[i] = END;
	return (b);
}

ssize_t			len_stack(long *st, ssize_t block)
{
	ssize_t		len;

	len = 0;
	while (st[len] < block)
		len++;
	return (len);
}

static int		check(long *a, long *b)
{
	ssize_t		i;

	i = 0;
	if (b[0] != END)
		return (FALSE);
	while (a[i++] != END)
	{
		if (a[i] < a[i - 1])
			return (FALSE);
	}
	return (TRUE);
}

static void		sort(long *a, long *b)
{
	ssize_t		i;

	if (!check(a, b))
	{
		if (!check_rev(a, b))
		{
			i = len_stack(a, END);
			if (i == 3)
				sort_three(a, i);
			else if (i != 5 && i != 6)
				separation_steck_a(a, b, END, FALSE);
			else
				sort_steck_a(a, b, i);
		}
	}
	free(a);
	free(b);
}

int				main(int argc, char **argv)
{
	long		*a;
	long		*b;
	ssize_t		max_min_len[4];

	max_min_len[LEN] = 0;
	if (argc == 1 || !(a = save_input(++argv, max_min_len)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!(check_input(a, max_min_len, 0)))
	{
		free(a);
		ft_putstr("Error\n");
	}
	else
	{
		b = init_steck_b(max_min_len[LEN]);
		sort(a, b);
	}
	return (0);
}
