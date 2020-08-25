/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:09:36 by armendes          #+#    #+#             */
/*   Updated: 2020/08/25 21:01:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

ul		ver_x(ul i, ul x, ul len)
{
	if (i >= x && i <= x + len - 1)
		return (1);
	return (0);
}

ul		ver_y(ul j, ul y, ul len)
{
	if (j >= y && j <= y + len - 1)
		return (1);
	return (0);
}

void	disp(ul x, ul y, ul len, char *name)
{
	ul		i;
	ul		j;
	int		fd;
	char	c;

	j = 0;
	if ((fd = open(e->name, O_RDONLY)) == -1)
		return ;
	while (read(fd, &c, 1) && c != '\n')
		i = 0;
	while (read(fd, &c, 1))
	{
		if (c == e->obstacle)
			ft_putchar(e->obstacle);
		else if (c == e->vide && ver_x(i, x, len) && ver_y(j, y, len))
			ft_putchar(e->plein);
		else if (c == e->vide)
			ft_putchar(e->vide);
		j++;
		if (c == '\n' && (j = 0) == 0)
		{
			ft_putchar('\n');
			i++;
		}
	}
	if (close(fd) == -1)
		return ;
}

void	check_valid(ul **tab, ul x, ul y, ul len)
{
	ul t1;
	ul t2;
	ul t3;
	ul t4;

	t1 = tab[x][y];
	t2 = tab[x + len - 1][y];
	t3 = tab[x][y + len - 1];
	t4 = tab[x + len - 1][y + len - 1];
	if ((t4 - t2 - t3 - t1) > 0)
		return (0);
	return (1);
}

void	solve(ul **tab, ul xbord, ul ybord, ul len)
{
	ul x;
	ul y;
	ul xtmp;
	ul ytmp;
	ul lentmp;

	lentmp = 0;
	while ((x + len - 1) <= xbord && (y + len - 1) <= ybord)
	{
		if (check_valid(tab, x, y, len))
		{
			xtmp = x;
			ytmp = y;
			lentmp = len;
			solve(tab, xbord, ybord, len + 1);
		}
		if ((y + len) == (ybord - 1))
		{
			x++;
			y = 0;
		}
		y++;
	}
	if (lentmp != 0)
		return ;
}
