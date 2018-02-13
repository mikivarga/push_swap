/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:28:32 by mvarga            #+#    #+#             */
/*   Updated: 2018/01/31 15:30:23 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == ' ')
		return (TRUE);
	return (FALSE);
}

int			check(long *a, long *b)
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

void		show_instructions(void)
{
	ft_putstr("1) sa : swap a - swap the first 2 elements");
	ft_putstr(" at the top of stack a.\n");
	ft_putstr("2) sb : swap b - swap the first 2 elements");
	ft_putstr(" at the top of stack b.\n");
	ft_putstr("3) sa and sb at the same time\n");
	ft_putstr("4) pa : push a - take the first element at the");
	ft_putstr(" top of b and put it at the top of a.\n");
	ft_putstr("5) pb : push b - take the first element at the");
	ft_putstr(" top of a and put it at the top of b.\n");
	ft_putstr("6) ra : rotate a - shift up all elements of stack a by 1.");
	ft_putstr(" The first element becomes the last one.\n");
	ft_putstr("7) rb : rotate b - shift up all elements of stack b by 1.");
	ft_putstr(" The first element becomes the last one.\n");
	ft_putstr("8) ra and rb at the same time.");
	ft_putstr("9) rra : reverse rotate a - shift down all");
	ft_putstr(" elements of stack a by 1.");
	ft_putstr(" The last element becomes the first one.\n");
	ft_putstr("10) rrb : reverse rotate b - shift down all");
	ft_putstr(" elements of stack b by 1.");
	ft_putstr(" The last element becomes the first one.\n");
	ft_putstr("11) rrr : rra and rrb at the same time.\n");
}
