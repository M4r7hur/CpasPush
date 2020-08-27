/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:30:56 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/27 11:09:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

ul		matoi(char *str)
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

ul		check_maperr(char **str, t_minfo *minfo)
{
	ul		i;
	ul		j;
	ul		tmp;
	ul		nbnobs;

	i = -1;
	tmp = len(str[0]);
	nbnobs = 0;
	while (++i < minfo->nbl)
	{
		j = -1;
		while (str[i][++j])
		{
			if (!(str[i][j] == minfo->obs || str[i][j] == minfo->nobs))
				return (1);
			if (str[i][j] == minfo->nobs)
				nbnobs++;
			}
		if (j != tmp)
			return (1);
	}
	if (nbnobs == 0)
		return (1);
	return (0);
}

void		free_malloc(t_minfo *minfo)
{
	ul		i;
	
	i = 0;
	while (i <= minfo->nbl)
	{
		free(minfo->map[i]);
		i++;
	}
	free(minfo->map);
}
