/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 10:13:06 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 15:22:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

int		verif_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

char	**cut(char *str, int x)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(result = malloc(sizeof(char *) * 2)))
		return (NULL);
	while (i < 2)
	{
		while (j < 4)
		{
			if (j == 0)
				if (!(result[i] = malloc(sizeof(char) * 5)))
					return (NULL);
			result[i][j] = str[x];
			x += 2;
			j++;
		}
		result[i][j] = '\0';
		j = 0;
		i++;
	}
	return (result);
}
