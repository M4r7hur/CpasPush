/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:48:11 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 14:54:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int		main(int ac, char **av)
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
}*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int g_stop = 0;

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

void	solve(int *columnU, int *columnD, int *rowL, int *rowR, int row, int col)
{
	int val;

	val = 1;
	while (val <= 4)
	{
	    if (g_stop == 1)
	    {
	        return ;
	    }
    		if (place(row, col, val))
    		{
    			g_tab[row][col] = val;
    			if (col == 3 && place_row(rowL, row) && place_row_rev(rowR, row))
    			{
    				if (row == 3 && place_col(columnU) && place_col_rev(columnD))
    				{
    					disp();
    					g_stop = 1;
    					return ;
    				}
    				solve(columnU, columnD, rowL, rowR, row + 1, 0);
    			}
    			else
    				solve(columnU, columnD, rowL, rowR, row, col + 1);
    		}
		val++;
	}
}

int        main(void)
{
    int    columnU[4];
    int    columnD[4];
    columnU[0] = 2;
    columnU[1] = 2;
    columnU[2] = 1;
    columnU[3] = 2;

    columnD[0] = 2;
    columnD[1] = 1;
    columnD[2] = 4;
    columnD[3] = 3;

    int    rowL[4];
    int    rowR[4];
    rowL[0] = 3;
    rowL[1] = 4;
    rowL[2] = 1;
    rowL[3] = 2;

    rowR[0] = 2;
    rowR[1] = 1;
    rowR[2] = 2;
    rowR[3] = 2;

    solve(columnU, columnD, rowL, rowR, 0, 0);
}


