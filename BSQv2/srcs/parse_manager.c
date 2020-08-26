/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:16:21 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 20:36:09 by seciurte         ###   ########.fr       */
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
	if (!(minfo->map = malloc(sizeof(char*) * minfo->nbl)))
		return (NULL);
	map = get_raw_map(fd, name, cursor);
	minfo->map = msplit(map, "\n");
	return (minfo);
}

ul		get_map_info(t_minfo *minfo, int fd, char *name)
{
	char		fline[2048];
	ul			i;

	i = 0;
	read(fd, &fline, 2048);
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

void	reset_cursor(int fd, char *name)
{
	if ((close(fd)) == -1)
		return ;
	if ((fd = open(name, O_RDONLY)) == -1)
		return ;
}

char	*get_raw_map(int fd, char *name, ul cursor)
{
	ul		i;
	char	buf;
	char	*str;

	i = 0;
	while (i < cursor && read(fd, &buf, 1))
		i++;
	i = 0;
	while (read(fd, &buf, 1))
		i++;
	if (!(str = malloc(sizeof(char) * i)))
		return (NULL);
	reset_cursor(fd, name);
	i = 0;
	while (read(fd, &buf, 1))
	{
		str[i] = buf;
		i++;
	}
	reset_cursor(fd, name);
	return (str);
}
