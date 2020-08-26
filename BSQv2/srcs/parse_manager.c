/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:22:14 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 18:58:36 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

t_minfo		*get_entry_from_file(int fd, char *name)
{
	t_minfo	*minfo;
	char	*str;

	if (!(minfo = malloc(sizeof(t_minfo))))
	   return (NULL);	
	str = get_str(minfo, fd, name);
	minfo->map = msplit(str, "\n");
	return (minfo);
}

t_minfo		*get_entry_from_stdin()
{
	char	buf[16384];
	t_minfo	*minfo;

	read(0, &buf, 16384);
	minfo = get_map_info(buf);
	if (!(minfo->map = malloc(sizeof(char*) * minfo->nbl)))
		return (NULL);
	get_map(minfo, buf);
	return (minfo);
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
	buf[i - 3] = '\0';
	minfo->nbl = matoi(buf);
	minfo->cursor = i;
	return (minfo);
}

void	get_map(t_minfo	*minfo, char *buf)
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
		printf("i = %ld | j = %ld | tmp = %ld\n", i, j, tmp);
		if (j != tmp)
		{
			write(2, "map error\n", 10);
			free_mall(minfo, i);
			return ;
		}
		get_line_stdin(minfo, i, j);
		i++;
	}
}

void	get_line_stdin(t_minfo *minfo, ul i, ul size)
{
	ul	k;

	k = 0;
	if (!(minfo->map[i] = malloc(sizeof(char) * size)))
		return ;
	while (k < size)
	{
		minfo->map[i][k] = minfo->cursor;
		minfo->cursor++;
		k++;
	}
	minfo->map[i][k] = '\0';
}
