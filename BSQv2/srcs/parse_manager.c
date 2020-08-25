/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:22:14 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/25 21:01:48 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_minfo		*get_entry_from_file(int fd, char *name)
{
	
}

t_minfo		*get_entry_from_stdin()
{
	char	buf[2048];
	t_minfo	*minfo;
	ul		i;

	read(0, &buf, 2048);
	minfo = get_map_info(buf);
	if (!(minfo->map = malloc(sizeof(char*) * nbl)))
		return (NULL);
	get_map(minfo);
}

t_minfo		*get_map_info(char	*line)
{
	t_minfo			*minfo;
	static ul		i;

	if (!(minfo = malloc(sizeof(t_minfo))))
		return (NULL);
	i = 0;
	while (line[i])
		i++;
	minfo->fill = line[i - 1];
	minfo->obs = line[i - 2];
	minfo->nobs = line[i - 3];
	line[i - 3] = '\0';
	minfo->nbl = ft_atoi(line);
	return (minfo);
}

void	get_map(t_minfo	minfo)
{
	ul		i;
	ul		j;
	ul		tmp;
	char	line[2048];

	i = 0;
	while (i < minfo->nbl)
	{
		read(0, &line, 2048);
		if (i == 0)
			tmp = len(line);
		if (!(minfo->map = malloc(sizeof(char) * tmp)))
			return (NULL);

	}
}

void	add_line(t_minfo)
