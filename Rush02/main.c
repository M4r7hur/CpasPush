/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 09:53:31 by armendes          #+#    #+#             */
/*   Updated: 2020/08/22 11:15:39 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (str_is_numeric(av[1]))
		{
		}
		else
			ft_putstr("Error\n");
	}
	else if (ac == 3)
	{
		if (str_is_numeric(av[2]))
		{
		}
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
}
