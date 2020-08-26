/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:53:20 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 19:05:22 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void	free_mall(t_minfo *minfo, ul i)
{
	ul	k;

	k = 0;
	while (k < i)
	{
		free(minfo->map[k]);
		k++;
	}
	free(minfo->map);
}

void	reset_cursor(int fd, char *name)
{
	if (!(close(fd)))
		return ;
	if (!(fd = open(name, O_RDONLY)))
		return ;
}

char	*get_str(t_minfo *minfo, int fd, char *name)
{
	ul 	i;
	char	buf;
	char	*str;
	char	line[5000];

	i = 0;
	minfo->cursor = 0;
	while (read(fd, &buf, 1))
		minfo->cursor++;
	if (!(str = malloc(sizeof(char) * minfo->cursor)))
		return (NULL);
	reset_cursor(fd, name);
	buf = 'a';
	while (read(fd, &buf, 1) && buf != '\n')
	{
		line[i] = buf;
		i++;
	}
	line[i] = '\0';
	set_minfo(minfo, line, i);
	if (!(str = malloc(sizeof(char*) * minfo->cursor)))
		return (NULL);
	while (read(fd, &buf, 1))
		i++;
	read(fd, &str, minfo->cursor);
	return (str);
}

void	set_minfo(t_minfo *minfo, char *str, ul i)
{
	printf("%ld\n", i);
	minfo->fill = str[i - 1];
	minfo->obs = str[i - 2];
	minfo->nobs = str[i - 3];
	str[i - 3] = '\0';
	minfo->nbl = matoi(str);
}
