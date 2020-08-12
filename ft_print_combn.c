/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:25:54 by armendes          #+#    #+#             */
/*   Updated: 2020/08/12 10:08:42 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_tab[10];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	disp(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(g_tab[i] + 48);
		i++;
	}
	if (g_tab[0] != (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int		place(int row, int col)
{
	if (row == 0)
		return (1);
	if (g_tab[row - 1] >= col)
		return (0);
	return (1);
}

void	solve(int row, int n)
{
	int col;

	col = 0;
	while (col <= 9)
	{
		if (place(row, col))
		{
			g_tab[row] = col;
			if (row == (n - 1))
				disp(n);
			else
				solve(row + 1, n);
		}
		col++;
	}
}

void	ft_print_combn(int n)
{
	if (n <= 0 || n >= 10)
		return ;
	solve(0, n);
}
