/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:01:04 by armendes          #+#    #+#             */
/*   Updated: 2020/08/25 18:50:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ver_x(long i, long x, long len)
{
	if (i >= x && i <= x + len - 1)
		return (1);
	return (0);
}

long	ver_y(long j, long y, long len)
{
	if (j >= y && j <= y + len - 1)
		return (1);
	return (0);
}

void	disp(long x, long y, t_param *e, long len)
{
	long	i;
	long	j;
	long	fd;
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

long	check_obst(long x, long y, t_list *begin_list, long len)
{
	long	xmax;
	long	ymax;
	long	xtmp;
	long	ytmp;

	xmax = x + len - 1;
	ymax = y + len - 1;
	while (begin_list)
	{
		xtmp = begin_list->x;
		ytmp = begin_list->y;
		if (xtmp >= x && xtmp <= xmax && ytmp >= y && ytmp <= ymax)
			return (0);
		if (ytmp > y)
			begin_list = begin_list->next;
		else
			begin_list = begin_list->next;
	}
	return (1);
}

void	fonction_transit(long *y, long *ymax)
{
	*y += 1;
	*ymax += 1;
}

void	set_x_y_tmp(long *x, long *y, long *xtmp, long *ytmp)
{
	*xtmp = *x;
	*ytmp = *y;
}

void	set_len(long *len, long *maxlen, long *lentmp)
{
	*lentmp = *len;
	*maxlen = *len;
}

void	solve2(long x, long y, t_param *params, long len)
{
	long xtmp;
	long ytmp;
	long lentmp;
	long xmax;
	long ymax;
	static long maxlen;

	xtmp = 0;
	ytmp = 0;
	lentmp = 0;
	if (len > params->xmax)
		return ;
	xmax = x + len - 1;
	ymax = y + len - 1;
	while (xmax < params->xmax && ymax < params->ymax)
	{
		if (check_obst(x, y, params->next, len))
		{
			set_x_y_tmp(&x, &y, &xtmp, &ytmp);
			set_len(&len, &maxlen, &lentmp);
			solve2(0, 0, params, len + 1);
			break ;
		}
		if (ymax == params->ymax - 1)
		{
			x++;
			y = 0;
			xmax++;
			ymax = y + len - 1;
		}
		else
			fonction_transit(&y, &ymax);
	}
	if (lentmp == maxlen)
		disp(x, y, params, len);
}
