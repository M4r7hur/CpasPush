/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:30:56 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/25 21:00:43 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

ul		ft_atoi(char *str)
{
	ul i;
	ul nbr;
	ul fsign;

	i = 0;
	nbr = 0;
	fsign = 1;
	while ((str[i] == '\f' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\t' || str[i] == '\v' || str[i] == ' ') && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			fsign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * fsign);
}

ul		len(char *str)
{
	ul	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
