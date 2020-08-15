/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:48:11 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 11:57:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int		g_tab[4][4];

void	disp()
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			ft_putnbr(g_tab[i][j]);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	solve(char **columns, char **rows, int row, int col)
{
	int val;

	val = 1;
	while (val <= 4)
	{
		if (place(row, col, val))
		{
			g_tab[row][col] = val;
			if (col == 3 && place_row(rows, row) && place_row_rev(rows, row))
			{
				if (row == 3 && place_col(columns) && place_col_rev(columns))
				{
					disp();
					return ;
				}
				solve(columns, rows, row + 1, 0);
			}
			else
				solve(columns, rows, row, col + 1);
		}
		val++;
	}
}

int		main(int ac, char **av)
{
	char	**columns;
	char	**rows;

	if (ac == 2)
	{
		if (verif_arg(av[1]))
		{
			columns = cut(av[1], 0);
			rows = cut(av[1], 16);
			solve(columns, rows, 0, 0);
		}
		else
			ft_putstr("L'argument n'est pas valide.\n");
	}
	else
		ft_putstr("Le nombre d'arguments est incorrect.\n");
}
