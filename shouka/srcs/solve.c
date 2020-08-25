/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:01:04 by armendes          #+#    #+#             */
/*   Updated: 2020/08/25 12:32:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ver_x(int i, int x, int len)
{
	if (i >= x && i <= x + len)
		return (1);
	return (0);
}

int		ver_y(int j, int y, int len)
{
	if (j >= y && j <= y + len)
		return (1);
	return (0);
}

void	disp(int x, int y, t_param *e, int len)
{
	int		i;
	int		j;
	int		fd;
	char	c;

	i = -1;
	j = 0;
	if ((fd = open(e->name, O_RDONLY)) == -1)
		return ;
	while (read(fd, &c, 1) && c != '\n');
	i++;
	while (read(fd, &c, 1))
	{
		if (c == e->obstacle)
			ft_putchar(e->obstacle);
		else if (c == e->vide && ver_x(i, x, len) && ver_y(j, y, len))
			ft_putchar(e->plein);
		else if (c == e->vide && (!ver_x(i, x, len) || !ver_y(j, y, len)))
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

int		check_obst(int x, int y, t_list *begin_list, int len)
{
	int xmax;
	int ymax;
	int	xtmp;
	int ytmp;

	xmax = x + len;
	ymax = y + len;
	ft_putchar('-');
	ft_putchar(x + 48);
	ft_putchar(' ');
	ft_putchar(y + 48);
	ft_putchar(' ');
	ft_putchar(len + 48);	
	ft_putchar(' ');
	ft_putchar(xmax + 48);
	ft_putchar(' ');
	ft_putchar(ymax + 48);
	ft_putchar('-');
	ft_putchar('\n');
	while (begin_list->x <= xmax && begin_list->y <= ymax && begin_list)
	{
		xtmp = begin_list->x;
		ytmp = begin_list->y;
		ft_putchar(' ');
		ft_putchar(xtmp + 48);
		ft_putchar(' ');
		ft_putchar(ytmp + 48);
		ft_putchar('-');
		ft_putchar('\n');
		if (xtmp >= x && xtmp <= xmax && ytmp >= y && y <= ymax)
			return (0);
		if (ytmp > y)
			begin_list = begin_list->next_line;
		else
			begin_list = begin_list->next;
	}
	return (1);
}

void	solve(int xbord, int ybord, t_param *params, int len)
{
	int x;
	int y;
	int xmax;
	int ymax;

	if (len < 0)
		return ;
	x = 0;
	y = 0;
	xmax = x + len;
	ymax = y + len;
	while (xmax <= xbord && ymax <= ybord)
	{
		ft_putchar(x + 48);
		ft_putchar(' ');
		ft_putchar(y + 48);
		ft_putchar(' ');
		ft_putchar(len + 48);	
		ft_putchar(' ');
		ft_putchar(xmax + 48);
		ft_putchar(' ');
		ft_putchar(ymax + 48);
		ft_putchar('\n');
		if (check_obst(x, y, params->next, len))
		{
			disp(x, y, params, len);
			return ;
		}
		if (ymax == ybord)
		{
			x++;
			y = 0;
			xmax++;
			ymax = y + len;
		}
		else
		{
			y++;
			ymax++;
		}
	}
	solve(xbord, ybord, params, len - 1);
}
