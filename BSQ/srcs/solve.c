/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:01:04 by armendes          #+#    #+#             */
/*   Updated: 2020/08/24 13:44:21 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	int		bytes_read;
	char	buff[1];

	i = 0;
	j = 0;
	if ((fd = open(e->name, O_RDONLY)) == -1)
		return ;
	while ((bytes_read = read(fd, buff, 1)))
	{
		if (buff[0] == e->obstacle)
			ft_putchar(e->obstacle);
		else if (buff[0] == e->vide && ver_x(i, x, len) && ver_y(j, y, len))
			ft_putchar(e->plein);
		else if (buff[0] == e->vide && !ver_x(i, x, len) && !ver_y(j, y, len))
			ft_putchar(e->vide);
		j++;
		if (buff[0] == '\n' && (j = 0) == 0)
		{
			ft_putchar('\n');
			i++;
		}
	}
}

int		check_obst(int x, int y, t_list *begin_list, int len)
{
	int xmax;
	int ymax;
	int	xtmp;
	int ytmp;

	xmax = x + len;
	ymax = y + len;
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

void	solve(int xbord, int ybord, t_param *begin_list, int len)
{
	int x;
	int y;
	int xmax;
	int ymax;

	x = 0;
	y = 0;
	xmax = x + len;
	ymax = y + len;
	while (xmax <= xbord && ymax <= ybord)
	{
		if (check_obst(x, y, begin_list->next, len))
		{
			disp(x, y, begin_list, len);
			return ;
		}
		x++;
		y++;
		xmax++;
		ymax++;
	}
	solve(xbord, ybord, begin_list, len - 1);
}
