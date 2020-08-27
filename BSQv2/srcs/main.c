/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:04:22 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/27 10:38:24 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int ac, char **av)
{
	int		i;
	t_minfo *minfo;
	ul		**tab;

	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
		{
			if ((minfo = get_minfo_file(av[i])) != NULL)
			{
				tab = change(minfo);
				solve(tab, minfo, 1);
			}
		}
	}
	else
	{
		i = 1;
	}
}
