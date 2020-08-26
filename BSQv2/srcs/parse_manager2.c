/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:53:20 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 12:21:08 by seciurte         ###   ########.fr       */
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

ul		get_line_size(char *name)
{
	ul		i;
	int		fd;
	char	buf;
	
	i = 0;
	if (!(fd = open(name, O_RDONLY)))
		return (0);
	while (read(fd, &buf, O_RDONLY))
		i++;
	
}
