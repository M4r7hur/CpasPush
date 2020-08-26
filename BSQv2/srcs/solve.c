/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:09:36 by armendes          #+#    #+#             */
/*   Updated: 2020/08/26 20:50:28 by seciurte         ###   ########.fr       */
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

int		check_valid(ul **tab, ul x, ul y, ul len)
{
	if (x == 0 && y == 0)
	{
		if (tab[x + len - 1][y + len - 1] > 0)
			return (0);
	}
	else if (x == 0 && y != 0)
	{
		if ((tab[x + len - 1][y + len - 1] - tab[x + len - 1][y - 1]) > 0)
			return (0);
	}
	else if (x != 0 && y == 0)
	{
		if ((tab[x + len - 1][y + len - 1] - tab[x - 1][y + len - 1]) > 0)
			return (0);
	}
	else if (x != 0 && y != 0)
	{
		if ((tab[x + len - 1][y + len - 1] - tab[x + len - 1][y - 1] -
					tab[x - 1][y + len - 1] + tab[x - 1][y - 1]) > 0)
			return (0);
	}
	return (1);
}
