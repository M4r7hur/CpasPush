/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:16:21 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/27 11:21:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_minfo		*get_minfo_file(char *name)
{
	int			fd;
	t_minfo		*minfo;
	ul			cursor;
	char		*map;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	if (!(minfo = malloc(sizeof(t_minfo))))
		return (NULL);
	cursor = get_map_info(minfo, fd, name);
	map = get_raw_map(fd, name);
	minfo->map = msplit(map, "\n");
	free(map);
	minfo->nbc = len(minfo->map[0]);
	if (check_maperr(minfo->map, minfo))
	{
		write(2, "map error\n", 10);
		free_malloc(minfo);
		free(minfo);
		return (NULL);
	}
	return (minfo);
}

ul			get_map_info(t_minfo *minfo, int fd, char *name)
{
	char		fline[500];
	ul			i;

	i = 0;
	read(fd, &fline, 500);
	while (fline[i] != '\n')
		i++;
	minfo->fill = fline[i - 1];
	minfo->obs = fline[i - 2];
	minfo->nobs = fline[i - 3];
	fline[i - 3] = '\0';
	minfo->nbl = matoi(fline);
	reset_cursor(fd, name);
	return (i);
}

void		reset_cursor(int fd, char *name)
{
	if ((close(fd)) == -1)
		return ;
	if ((fd = open(name, O_RDONLY)) == -1)
		return ;
}

char		*get_raw_map(int fd, char *name)
{
	ul		i;
	ul		max;
	char	buf;
	char	*str;

	i = 0;
	while (read(fd, &buf, 1) && buf == '\n')
		i++;
	i = 0;
	while (read(fd, &buf, 1))
		i++;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	reset_cursor(fd, name);
	max = i + 1;
	while (read(fd, &buf, 1) && buf != '\n')
		i++;
	i = -1;
	while (++i < max && read(fd, &buf, 1))
		str[i] = buf;
	str[i] = '\0';
	reset_cursor(fd, name);
	return (str);
}
