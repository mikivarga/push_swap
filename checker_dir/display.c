/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:21:25 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:23:59 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		show_steck_a(long *a, long *b, ssize_t *colour, ssize_t i)
{
	char		*nmb;

	if (a[i] < END)
	{
		nmb = ft_itoa(a[i]);
		write(1, "|           ", 12 - ft_strlen(nmb));
		if (colour[0] == i)
			ft_putstr("\033[1;32m");
		if (colour[1] == i)
			ft_putstr("\033[1;33m");
		write(1, nmb, ft_strlen(nmb));
		if (colour[0] == i || colour[1] == i)
			ft_putstr("\033[0m");
		free(nmb);
		write(1, " | |", 4);
	}
	else if (b[i] < END)
	{
		if (a[i] == END)
			write(1, "|", 1);
		write(1, "            | |", 15);
	}
}

static void		show_steck_b(long *a, long *b, ssize_t *colour, ssize_t i)
{
	char		*nmb;

	if (b[i] < END)
	{
		nmb = ft_itoa(b[i]);
		write(1, "           ", 11 - ft_strlen(nmb));
		if (colour[0] == i)
			ft_putstr("\033[1;32m");
		if (colour[1] == i)
			ft_putstr("\033[1;33m");
		write(1, nmb, ft_strlen(nmb));
		if (colour[0] == i || colour[1] == i)
			ft_putstr("\033[0m");
		free(nmb);
		write(1, " |", 2);
	}
	if (a[i] < END && b[i] == END)
		write(1, "            |\n", 14);
	else if (a[i] < END || b[i] < END)
		write(1, "\n", 1);
}

static void		colour_a(long *a, ssize_t *colour, char *instr, int *flags)
{
	colour[0] = -1;
	colour[1] = -1;
	if (!flags[COLOUR] || !instr)
		return ;
	if (!ft_strcmp(instr, "sa") || !ft_strcmp(instr, "ss"))
	{
		colour[0] = 0;
		colour[1] = 1;
	}
	else if (!ft_strcmp(instr, "pa"))
		colour[0] = 0;
	else if (!ft_strcmp(instr, "ra") || !ft_strcmp(instr, "rr"))
		colour[0] = len_stack(a, END) - 1;
	else if (!ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrr"))
		colour[0] = 0;
}

static void		colour_b(long *b, ssize_t *colour, char *instr, int *flags)
{
	colour[0] = -1;
	colour[1] = -1;
	if (!flags[COLOUR] || !instr)
		return ;
	if (!ft_strcmp(instr, "sb") || !ft_strcmp(instr, "ss"))
	{
		colour[0] = 0;
		colour[1] = 1;
	}
	else if (!ft_strcmp(instr, "pb"))
		colour[0] = 0;
	else if (!ft_strcmp(instr, "rb") || !ft_strcmp(instr, "rr"))
		colour[0] = len_stack(b, END) - 1;
	else if (!ft_strcmp(instr, "rrb") || !ft_strcmp(instr, "rrr"))
		colour[0] = 0;
}

void			show(long *a, long *b, int *flags, char *instr)
{
	ssize_t		i;
	ssize_t		size;
	ssize_t		col_a[2];
	ssize_t		col_b[2];

	if (!flags[DISPLAY])
		return ;
	size = len_stack(a, END) + len_stack(b, END);
	if (!instr)
		write(1, "\nInit a and b:\n\n", 16);
	else
		write(1, "\n", 1);
	i = -1;
	while (++i < size)
	{
		colour_a(a, col_a, instr, flags);
		show_steck_a(a, b, col_a, i);
		colour_b(b, col_b, instr, flags);
		show_steck_b(a, b, col_b, i);
	}
	write(1, "|____________| |____________|\n", 30);
	write(1, "|     a      | |     b      |\n\n", 31);
}
