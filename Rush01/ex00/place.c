/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:01:59 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 11:06:28 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		place(int row, int col, int val)
{
	int x;

	x = 0;
	while (x < col)
	{
		if (tab[row][x] == val)
			return (0);
		x++;
	}
	x = 0;
	while (x < row)
	{
		if (tab[x][col] == val)
			return (0);
		x++;
	}
	return (1);
}

int		place_row(char **rows, int row)
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
			result++;
			if (g_tab[row][i + 1] > max)
				max = g_tab[row][i + 1];
		}
		else
			if (g_tab[row][i] > max)
				max = g_tab[row][i];
		i++;
	}
	if (result != rows[0][row])
		return (0);
	return (1);
}

int		place_row_rev(char **rows, int row)
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
			result++;
			if (g_tab[row][i - 1] > max)
				max = g_tab[row][i - 1];
		}
		else
			if (g_tab[row][i] > max)
				max = g_tab[row][i];
		i--;
	}
	if (result != rows[1][row])
		return (0);
	return (1);
}

int		place_col(char **columns)
{
	int i;
	int max;
	int result;
	int col;

	i = 0;
	result = 1;
	col = 0;
	while (col < 4)
	{
		max = g_tab[i][col];
		while (i < 3)
		{
			if (g_tab[i][col] < g_tab[i + 1][col] && g_tab[i + 1][col] > max)
			{
				result++;
				if (g_tab[i + 1][col] > max)
					max = g_tab[i + 1][col];
			}
			else
				if (g_tab[i + 1][col] > max)
					max = g_tab[i + 1][col];
			i++;
		}
		if (result != columns[0][col])
			return (0);
		col++;
	}
	return (1);
}

int		place_col_rev(char **colums, char **rows)
{
	int i;
	int max;
	int result;
	int col;

	i = 3;
	result = 1;
	col = 0;
	while (col < 4)
	{
		max = g_tab[i][col];
		while (i > 0)
		{
			if (g_tab[i][col] < g_tab[i - 1][col] && g_tab[i - 1][col] > max)
			{
				result++;
				if (g_tab[i - 1][col] > max)
					max = g_tab[i - 1][col];
			}
			else
				if (g_tab[i - 1][col] > max)
					max = g_tab[i - 1][col];
			i--;
		}
		if (result != columns[1][col])
			return (0);
		col++;
	}
	return (1);

}
