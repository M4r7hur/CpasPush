/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:53:20 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 17:57:07 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib.h>

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

void	reset_cursor(int fd, *name)
{
	if (!(close(fd)))
		return ;
	if (!(fd = open(name, O_RDONLY)))
		return ;
}

char	**get_str(t_minfo *minfo, int fd, *name)
{
	ul 	i;
	char	buf;
	char	*str;
	char	line[500];

	i = 0;
	minfo->cursor = 0;
	while (read(fd, &buf, 1))
		minfo->cursor;
	if (!(str = malloc(sizeof(char) * i)))
		return (NULL);
	reset_cursor(int fd, name);
	while (read(fd, &buf, 1) && buf != '\n')
		line[i] = buf;
	line[i] = '\0';
	set_minfo(minfo, line);
}

void	set_minfo(t_minfo minfo, char *str)
{
	
}
