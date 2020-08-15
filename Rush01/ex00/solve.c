/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:48:11 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 11:06:36 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int	g_tab[4][4];

void	disp()
{

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
			solve(colums, rows, 0, 0);
		}
		else
			ft_putstr("L'argument n'est pas valide.\n");
	}
	else
		ft_putstr("Le nombre d'arguments est incorrect.\n");
}
