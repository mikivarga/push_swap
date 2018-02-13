/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:24:25 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:26:11 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

ssize_t					len_stack(long *st, ssize_t block)
{
	ssize_t	len;

	len = 0;
	while (st[len] < block)
		len++;
	return (len);
}

static inline void		show_prom(int flag)
{
	if (!flag)
		return ;
	write(0, "-----------------------\n", 24);
	write(0, " Please select one of: \n", 24);
	write(0, "-----------------------\n", 24);
	write(0, "(i) instructions;      \n", 24);
	write(0, "(s) is sorted.         \n", 24);
	write(0, "-----------------------\n", 24);
}

static char				**ch_fl(char **argv, char *tmp, int *flags)
{
	if (!ft_strcmp(*argv, "-v"))
	{
		if (flags[DISPLAY] == TRUE)
			return (FALSE);
		flags[DISPLAY] = TRUE;
	}
	else if (!ft_strcmp(*argv, "-c"))
	{
		if (flags[COLOUR] == TRUE)
			return (FALSE);
		flags[COLOUR] = TRUE;
	}
	else if (tmp[0] == '-' && !ft_isdigit(tmp[1]))
		return (NULL);
	else
		return (--argv);
	return (argv);
}

static char				**check_flags(char **argv, int *flags)
{
	char			tmp[14];

	argv++;
	ft_strncpy(tmp, *argv, 13);
	if (!ft_strcmp(tmp, "-v"))
		flags[DISPLAY] = TRUE;
	else if (!ft_strcmp(tmp, "-c"))
		flags[COLOUR] = TRUE;
	else if (tmp[0] == '-' && !ft_isdigit(tmp[1]))
		return (NULL);
	else
		return (--argv);
	argv++;
	ft_strncpy(tmp, *argv, 13);
	return (ch_fl(argv, tmp, flags));
}

int						main(int argc, char **argv)
{
	int				flags[2];

	if (argc != 1)
	{
		flags[DISPLAY] = FALSE;
		flags[COLOUR] = FALSE;
		if (!(argv = check_flags(argv, flags)))
			ft_putstr("Error\n");
		else
		{
			show_prom(flags[DISPLAY]);
			check_digits(++argv, flags);
		}
	}
	return (0);
}
