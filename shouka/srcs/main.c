/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 11:53:49 by armendes          #+#    #+#             */
/*   Updated: 2020/08/24 19:07:26 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	int			i;
	int			fd;
	t_param		*params;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if ((fd = open(av[i], O_RDONLY)) == -1)
				return (0);
			if ((params = get_map_info(fd, av[i])) != NULL)
			{
				solve(params->xmax, params->ymax, params, params->xmax);
			}
			i++;
		}
	}
}
