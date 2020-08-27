/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 20:08:43 by armendes          #+#    #+#             */
/*   Updated: 2020/08/27 11:10:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

ul		g_maxlen = 0;

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
