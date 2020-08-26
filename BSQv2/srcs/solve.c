/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:09:36 by armendes          #+#    #+#             */
/*   Updated: 2020/08/26 19:53:42 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

ul		g_maxlen = 0;

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

void	disp(ul x, ul y, ul len, t_minfo *info)
{
	ul		i;
	ul		j;

	i = 0;
	while (i < info->nbl)
	{
		j = 0;
		while (j < info->nbc)
		{
			if (info->map[i][j] == info->obs)
				ft_putchar(info->obs);
			else if (info->map[i][j] == info->nobs &&
					ver_x(i, x, len) && ver_y(j, y, len))
				ft_putchar(info->fill);
			else if (info->map[i][j] == info->nobs)
				ft_putchar(info->nobs);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	set_x_y_zero(ul *t1, ul *t2, ul *t3)
{
	*t1 = 0;
	*t2 = 0;
	*t3 = 0;
}

void	set_x_zero(ul *t1, ul *t3)
{
	*t1 = 0;
	*t3 = 0;
}

void	set_y_zero(ul *t1, ul *t2)
{
	*t1 = 0;
	*t2 = 0;
}

int		check_valid(ul **tab, ul x, ul y, ul len)
{
	ul t1;
	ul t2;
	ul t3;
	ul t4;

	if (x == 0 && y == 0)
		set_x_y_zero(&t1, &t2, &t3);
	else if (x == 0 && y != 0)
	{
		set_x_zero(&t1, &t3);
		t2 = tab[x + len - 1][y - 1];
	}
	else if (x != 0 && y == 0)
	{
		set_y_zero(&t1, &t2);
		t3 = tab[x - 1][y + len - 1];
	}
	else
	{
		t1 = tab[x - 1][y - 1];
		t2 = tab[x + len - 1][y - 1];
		t3 = tab[x - 1][y + len - 1];
	}
	t4 = tab[x + len - 1][y + len - 1];
	if ((t4 - t2 - t3 + t1) > 0)
		return (0);
	return (1);
}

void	set_tmp(ul *xtmp, ul x, ul *ytmp, ul y)
{
	*xtmp = x;
	*ytmp = y;
}

void	set_len(ul *lentmp, ul len)
{
	*lentmp = len;
	g_maxlen = len;
}

void	solve(ul **tab, t_minfo *info, ul len)
{
	ul			x;
	ul			y;
	ul			xtmp;
	ul			ytmp;
	ul			lentmp;

	x = 0;
	y = 0;
	lentmp = 0;
	while ((x + len - 1) < info->nbl && (y + len - 1) < info->nbc)
	{
		if (check_valid(tab, x, y, len))
		{
			set_tmp(&xtmp, x, &ytmp, y);
			set_len(&lentmp, len);
			solve(tab, info, len + 1);
			break ;
		}
		if ((y + len - 1) == (info->nbc) - 1 && (y = 0) == 0)
			x++;
		else
			y++;
	}
	if (lentmp == g_maxlen)
		disp(xtmp, ytmp, lentmp, info);
}
