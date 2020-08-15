/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:48:11 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 15:32:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	g_stop = 0;

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

void	solve(int *column_u, int *column_d, int *row_l, int *row_r, int row, int col)
{
	int val;

	val = 1;
	while (val <= 4)
	{
	    if (g_stop == 1)
	        return ;
    		if (place(row, col, val))
    		{
    			g_tab[row][col] = val;
    			if (col == 3 && place_row(row_l, row) && place_row_rev(row_r, row))
    			{
    				if (row == 3 && place_col(column_u) && place_col_rev(column_d))
    				{
    					disp();
    					g_stop = 1;
    					return ;
    				}
    				solve(column_u, column_d, row_l, row_r, row + 1, 0);
    			}
    			else
    				solve(column_u, column_d, row_l, row_r, row, col + 1);
    		}
		val++;
	}
}

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

int        main(void)
{
    int    columnU[4];
    int    columnD[4];
    columnU[0] = 1;
    columnU[1] = 3;
    columnU[2] = 2;
    columnU[3] = 2;

    columnD[0] = 3;
    columnD[1] = 1;
    columnD[2] = 2;
    columnD[3] = 2;

    int    rowL[4];
    int    rowR[4];
    rowL[0] = 1;
    rowL[1] = 3;
    rowL[2] = 2;
    rowL[3] = 2;

    rowR[0] = 2;
    rowR[1] = 2;
    rowR[2] = 1;
    rowR[3] = 3;

    solve(columnU, columnD, rowL, rowR, 0, 0);
}
