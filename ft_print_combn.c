/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:25:54 by armendes          #+#    #+#             */
/*   Updated: 2020/08/12 09:37:21 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	disp(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + 48);
		i++;
	}
}

int		place(int *tab, int row, int col)
{
	if (row == 0)
		return (1);
	if (tab[row - 1] >= col)
		return (0);
	return (1);
}

void	solve(int *tab, int row, int n)
{
	int col;

	col = 0;
	while (col <= (n - 1))
	{
		if (place(tab, row, col))
		{
			tab[row] = col;
			if (row == (n - 1))
				disp(tab, n);
			else
				solve(tab, row + 1, n);
		}
		col++;
	}
}

void	ft_print_combn(int n)
{
	int tab[n];

	if (n <= 0 || n >= 10)
		return ;
	else
		solve(tab, 0, n);
}

int main(void)
{
	ft_print_combn(9);
}
