/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:01:04 by armendes          #+#    #+#             */
/*   Updated: 2020/08/24 10:49:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		check_obst(int x, int y, int xmax, int ymax, t_list *begin_list)
{
	int	xtmp;
	int ytmp;

	while (begin_list)
	{
		xtmp = begin_list->x;
		ytmp = begin_list->y;
		if (xtmp >= x && xtmp <= xmax && ytmp >= y && y <= ymax)
			return (0);
		if (ytmp > y)
			begin_list = begin_list->next_line;
		else
			begin_list = begin_list->next;
	}
	return (1);
}

void	solve(int x, int y, int xbord, int ybord, t_list *begin_list)
{
	int xmax;
	int ymax;

	xmax = xbord;
	ymax = xmax;
	while (xmax <= xbord && ymax <= ybord)
	{
		if (check_obst(x, y, xmax, ymax, begin_list))
		{
			disp();
			return ;
		}
		x++;
		y++;
		xmax++;
		ymax++;
	}
}
