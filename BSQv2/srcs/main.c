/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:04:22 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 11:55:41 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int ac, char **av)
{
	ul	acs;
	ul	i;
	t_minfo *minfo;

	acs = (ul)ac;
	(void)av;
	i = 0;
	if (acs >1)
	{
		while (++i < ac)
		{
			minfo = get_entry_from_file(av[i]);
		}
	}
	else
	{
		get_entry_from_stdin();
	}
}
