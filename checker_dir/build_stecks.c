/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stecks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:28:08 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:28:12 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		find_instr_3(long *a, long *b, char *instr, int *flags)
{
	if (!ft_strcmp(instr, "rrb"))
	{
		if (reverse_rotate_b(b, FALSE))
			show(a, b, flags, instr);
	}
	else if (!ft_strcmp(instr, "rrr"))
	{
		if (reverse_rotate_rotate(a, b, FALSE))
			show(a, b, flags, instr);
	}
	else
	{
		free(a);
		free(b);
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
}

static void		find_instr_2(long *a, long *b, char *instr, int *flags)
{
	if (!ft_strcmp(instr, "rb"))
	{
		if (rotate_b(b, FALSE))
			show(a, b, flags, instr);
	}
	else if (!ft_strcmp(instr, "rr"))
	{
		if (rotate_rotate(a, b, FALSE))
			show(a, b, flags, instr);
	}
	else if (!ft_strcmp(instr, "rra"))
	{
		if (reverse_rotate_a(a, FALSE))
			show(a, b, flags, instr);
	}
	else
		find_instr_3(a, b, instr, flags);
}

static void		find_instr_1(long *a, long *b, char *instr, int *flags)
{
	if (!ft_strcmp(instr, "pa"))
	{
		if (push_a(a, b, FALSE))
			show(a, b, flags, instr);
	}
	else if (!ft_strcmp(instr, "pb"))
	{
		if (push_b(b, a, FALSE))
			show(a, b, flags, instr);
	}
	else if (!ft_strcmp(instr, "ra"))
	{
		if (rotate_a(a, FALSE))
			show(a, b, flags, instr);
	}
	else
		find_instr_2(a, b, instr, flags);
}

void			find_instr(long *a, long *b, char *instr, int *flags)
{
	if (!ft_strcmp(instr, "sa"))
	{
		if (swap_a(a, FALSE))
			show(a, b, flags, instr);
	}
	else if (!ft_strcmp(instr, "sb"))
	{
		if (swap_b(b, FALSE))
			show(a, b, flags, instr);
	}
	else if (!ft_strcmp(instr, "ss"))
	{
		if (swap_swap(a, b, FALSE))
			show(a, b, flags, instr);
	}
	else
		find_instr_1(a, b, instr, flags);
}

int				build_stecks(long *a, long *b, char *instr, int *flags)
{
	char		**cmd;
	ssize_t		i;

	cmd = ft_strsplit(instr, ' ');
	i = 0;
	while (cmd[i])
		find_instr(a, b, cmd[i++], flags);
	while (i)
		ft_strdel(&cmd[i--]);
	free(cmd);
	return (check(a, b));
}
