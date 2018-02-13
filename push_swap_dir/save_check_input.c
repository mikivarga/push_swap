/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_check_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:18:29 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 16:23:00 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline long		ft_str_to_long(const char *str)
{
	int		sign;
	long	rez;

	rez = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		rez = 10 * rez + (*str++ - '0');
	return (sign * rez);
}

static ssize_t			ft_cnt_digit(char **s,
ssize_t cnt, ssize_t i, int state)
{
	int		in;
	int		out;

	while (*s)
	{
		i = -1;
		in = TRUE;
		out = FALSE;
		state = out;
		while ((*s)[++i])
		{
			if ((*s)[i] == ' ')
				state = out;
			else if (state == out)
			{
				state = in;
				cnt++;
			}
			if ((*s)[i] != ' ' && (*s)[i]
				!= '-' && (*s)[i] != '+' && !ft_isdigit((*s)[i]))
				return (-1);
		}
		s++;
	}
	return (cnt);
}

static inline char		**check_digit(char **ar, long *a)
{
	if (**ar == '-' || **ar == '+')
	{
		(*ar)++;
		if (ft_isdigit(**ar))
			return (ar);
		else
		{
			free(a);
			a = NULL;
			return (NULL);
		}
	}
	return (ar);
}

long					*save_input(char **ar, ssize_t *max_min_len)
{
	long	*a;
	int		cnt;

	max_min_len[LEN] = ft_cnt_digit(ar, max_min_len[LEN], 0, FALSE);
	if (max_min_len[LEN] < 0)
		return (NULL);
	if (!(a = (long *)malloc(sizeof(long) * (max_min_len[LEN] + 1))))
		return (NULL);
	cnt = 0;
	while (cnt < max_min_len[LEN])
	{
		a[cnt++] = ft_str_to_long(*ar);
		while (**ar == ' ' || (**ar > 8 && **ar < 14))
			(*ar)++;
		if (!(ar = check_digit(ar, a)))
			return (NULL);
		while (ft_isdigit(**ar))
			(*ar)++;
		if (!(ar = check_digit(ar, a)))
			return (NULL);
		if (**ar == '\0')
			ar++;
	}
	a[cnt] = END;
	return (a);
}

int						check_input(long *a, ssize_t *max_min_len, ssize_t i)
{
	ssize_t		j;

	max_min_len[MAX] = a[i];
	max_min_len[MIN] = a[i];
	while (i < max_min_len[LEN])
	{
		if (a[i] > max_min_len[MAX])
			max_min_len[MAX] = a[i];
		else if (a[i] < max_min_len[MIN])
			max_min_len[MIN] = a[i];
		i++;
	}
	if ((-1L * max_min_len[MIN]) > MIN_I || max_min_len[MAX] > MAX_I)
		return (FALSE);
	i = -1;
	while (++i < max_min_len[LEN])
	{
		j = i + 1;
		while (j < max_min_len[LEN])
		{
			if (a[i] == a[j++])
				return (FALSE);
		}
	}
	return (TRUE);
}
