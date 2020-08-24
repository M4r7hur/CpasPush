/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:01:04 by armendes          #+#    #+#             */
/*   Updated: 2020/08/24 12:31:40 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"



void	disp(int xpos, int ypos, t_param *elem, int i)
{
	int		x;
	int		y;
	int		fd;
	int		bytes_read;
	char	buffer[1];

	x = 0;
	y = 0;
	if ((fd = open(elem->name, O_RDONLY)) == -1)
		return ;
	while ((bytes_read = read(fd, buffer, 1)))
	{
		if (buffer[0] == elem->obstacle)
			ft_putchar(elem->obstacle);
		else if (buffer[0] == elem->vide && x >= xpos && x <= xpos + i &&
				y >= ypos && y <= ypos + i)
			ft_putchar(elem->plein);
		else if (buffer[0] == elem->vide && !(x >= xpos && x <= xpos + i &&
				y >= ypos && y <= ypos + i))
			ft_putchar(elem->vide);
		y++;
		else if (buffer[0] == '\n')
		{
			ft_putchar('\n');
			x++;
			y = 0;
		}
	}
}

int		check_obst(int x, int y, t_list *begin_list, int i)
{
	int xmax;
	int ymax;
	int	xtmp;
	int ytmp;

	xmax = x + i;
	ymax = y + i;
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

void	solve(int xbord, int ybord, t_param *begin_list, int i)
{
	int x;
	int y;
	int xmax;
	int ymax;

	x = 0;
	y = 0;
	xmax = x + i;
	ymax = y + i;
	while (xmax <= xbord && ymax <= ybord)
	{
		if (check_obst(x, y, begin_list->next, i))
		{
			disp(x, y, begin_list, i);
			return ;
		}
		x++;
		y++;
		xmax++;
		ymax++;
	}
	solve(xbord, ybord, begin_list, i - 1);
}
