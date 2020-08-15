/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:01:59 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 15:55:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		place(int row, int col, int val)
{
	int x;

	x = 0;
	while (x < col)
	{
		if (g_tab[row][x] == val)
			return (0);
		x++;
	}
	x = 0;
	while (x < row)
	{
		if (g_tab[x][col] == val)
			return (0);
		x++;
	}
	return (1);
}

int		place_row(int *row_l, int row)
{
	int i;
	int max;
	int result;

	i = 0;
	max = g_tab[row][i];
	result = 1;
	while (i < 3)
	{
		if (g_tab[row][i] < g_tab[row][i + 1] && g_tab[row][i + 1] > max)
		{
			max = g_tab[row][i + 1];
			result++;
		}
		if (g_tab[row][i + 1] > max)
			max = g_tab[row][i + 1];
		i++;
	}
	if (result != row_l[row])
		return (0);
	return (1);
}

int		place_row_rev(int *row_r, int row)
{
	int i;
	int max;
	int result;

	i = 3;
	max = g_tab[row][i];
	result = 1;
	while (i > 0)
	{
		if (g_tab[row][i] < g_tab[row][i - 1] && g_tab[row][i - 1] > max)
		{
			max = g_tab[row][i - 1];
			result++;
		}
		if (g_tab[row][i] > max)
			max = g_tab[row][i];
		i--;
	}
	if (result != row_r[row])
		return (0);
	return (1);
}

int		place_col(int *column_u)
{
	int i;
	int max;
	int result;
	int col;

	col = -1;
	while (++col < 4)
	{
		i = -1;
		result = 1;
		max = g_tab[i + 1][col];
		while (++i < 3)
		{
			if (g_tab[i][col] < g_tab[i + 1][col] && g_tab[i + 1][col] > max)
			{
				max = g_tab[i + 1][col];
				result++;
			}
			if (g_tab[i + 1][col] > max)
				max = g_tab[i + 1][col];
		}
		if (result != column_u[col])
			return (0);
	}
	return (1);
}

int		place_col_rev(int *column_d)
{
	int i;
	int max;
	int result;
	int col;

	col = -1;
	while (++col < 4)
	{
		i = 4;
		result = 1;
		max = g_tab[i - 1][col];
		while (--i > 0)
		{
			if (g_tab[i][col] < g_tab[i - 1][col] && g_tab[i - 1][col] > max)
			{
				max = g_tab[i - 1][col];
				result++;
			}
			if (g_tab[i - 1][col] > max)
				max = g_tab[i - 1][col];
		}
		if (result != column_d[col])
			return (0);
	}
	return (1);
}
