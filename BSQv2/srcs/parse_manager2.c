/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:53:20 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 13:52:40 by seciurte         ###   ########.fr       */
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

void	get_line_file(char *name, t_minfo *minfo)
{
	ul		i;
	int		fd;
	char	buf;
	char	*line
	
	i = 0;
	if (!(fd = open(name, O_RDONLY)))
		return (0);
	while (read(fd, &buf, O_RDONLY) && buf != '\n')
		i++;
	if (!(close(fd)))
		return (0);
	if (!(line = malloc(sizeof(char))))
		return (NULL);
	if (!(fd = open(name, O_RDONLY)))
		return (0);
	read(fd, &line, i);
	minfo->fill = line[i - 1];
	minfo->obs = line[i - 2];
	minfo->nobs = line[i - 3];
	line[i - 3] = '\0';
	minfo->nbl = matoi(line);
}
