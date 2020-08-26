/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:22:14 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 11:04:51 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_minfo		*get_entry_from_file(int fd, char *name)
{
}

t_minfo		*get_entry_from_stdin()
{
	char	buf[16384];
	t_minfo	*minfo;
	ul		i;

	read(0, &buf, 16384);
	minfo = get_map_info(buf);
	if (!(minfo->map = malloc(sizeof(char*) * nbl)))
		return (NULL);
	get_map(minfo);
}

t_minfo		*get_map_info(char	*buf)
{
	t_minfo		*minfo;
	ul			i;

	if (!(minfo = malloc(sizeof(t_minfo))))
		return (NULL);
	i = 0;
	while (buf[i] != '\n')
		i++;
	minfo->fill = buf[i - 1];
	minfo->obs = buf[i - 2];
	minfo->nobs = buf[i - 3];
	line[i - 3] = '\0';
	minfo->nbl = ft_atoi(buf);
	minfo->cursor = i;
	return (minfo);
}

void	get_map(t_minfo	minfo, char buf)
{
	ul		i;
	ul		j;
	ul		tmp;

	i = 0;
	while (i < minfo->nbl)
	{
		j = len(buf);
		if (i == minfo->nbl)
			tmp = j;
		if (j != tmp)
		{
			write(2, "map error\n", 10);
			return (NULL)
		}
	}
}

void	get_line(t_minfo minfo, ul i, ul size)
{
	ul	k;
	
	k = 0;
	if (!(minfo->map[i] = malloc(sizeof(char) * size)))
		return (NULL);
	while (k < size)
	{
		minfo->map[i][k] = minfo->cursor;
		minfo->cursor++;
		k++;
	}
	minfo->map[i][k] = '\0';
}
