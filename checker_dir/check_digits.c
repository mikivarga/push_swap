/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:17:51 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:21:08 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void		status(long *a, long *b, int *flags)
{
	if (check(a, b))
	{
		if (flags[COLOUR])
			ft_putstr("\033[1;32m");
		ft_putstr("OK\n\n");
	}
	else
	{
		if (flags[COLOUR])
			ft_putstr("\033[1;31m");
		ft_putstr("KO\n\n");
	}
	if (flags[COLOUR])
		ft_putstr("\033[0m");
}

static int		check_buf(long *a, long *b, char *buf, int *flags)
{
	if (ft_isspace(buf[0]) || ft_isspace(buf[ft_strlen(buf) - 1]))
	{
		free(a);
		free(b);
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	if (flags[DISPLAY])
	{
		ft_putstr("\033[u\033[AExec ");
		ft_putstr_fd(buf, 1);
		ft_putstr(":\n\033[J");
	}
	if (buf[0] == 's' && buf[1] == '\0')
		return (FALSE);
	else if (buf[0] == 'i' && buf[1] == '\0')
		show_instructions();
	else
		build_stecks(a, b, buf, flags);
	if (check(a, b))
		return (FALSE);
	if (flags[DISPLAY])
		ft_putstr("\033[s\nExec ");
	return (TRUE);
}

static void		read_instr(long *a, long *b, int *flags)
{
	ssize_t		i;
	char		c;
	char		buf[100000];

	i = 0;
	if (flags[DISPLAY])
		ft_putstr("\033[s\nExec ");
	while ((read(0, &c, sizeof(char))) != 0)
	{
		buf[i] = c;
		if (buf[i] == '\n')
		{
			if (i != 0)
			{
				buf[i] = '\0';
				if (!check_buf(a, b, buf, flags))
					break ;
			}
			while (i)
				buf[i--] = '\0';
			i = 0;
		}
		else
			i++;
	}
}

void			check_digits(char **argv, int *flags)
{
	long		*a;
	long		*b;
	ssize_t		max_min_len[4];

	max_min_len[LEN] = 0;
	if (!(a = save_input(argv, max_min_len)))
		ft_putstr("Error\n");
	else
	{
		if (!(check_input(a, max_min_len, 0)))
		{
			free(a);
			ft_putstr("Error\n");
		}
		else
		{
			b = init_steck_b(max_min_len[LEN]);
			show(a, b, flags, NULL);
			read_instr(a, b, flags);
			status(a, b, flags);
			free(a);
			free(b);
		}
	}
}
