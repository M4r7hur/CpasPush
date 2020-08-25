/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:23 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/25 15:10:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long		ft_strlen(char *str)
{
	long i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long		ft_atoi(char *str)
{
	long i;
	long nbr;
	long fsign;

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
