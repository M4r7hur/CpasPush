/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:04:22 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 18:56:46 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int ac, char **av)
{
	ul	acs;
	ul	i;
	int	fd;
	t_minfo *minfo;

	acs = (ul)ac;
	(void)av;
	i = 0;
	if (acs >1)
	{
		while (++i < (ul)ac)
		{
			if (!(fd = open(av[i], O_RDONLY)))
				return (1);
			minfo = get_entry_from_file(fd, av[i]);
		}
	}
	else
	{
		get_entry_from_stdin();
	}
}
