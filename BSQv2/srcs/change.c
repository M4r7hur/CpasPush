/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:09:15 by armendes          #+#    #+#             */
/*   Updated: 2020/08/25 20:47:26 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

ul	convert(ul **tab, int i, int j, t_minfo info, char c)
{
	if (i == 0 && j == 0)
	{
		if (c == info->obs)
			return (1);
		return (0);
	}
	else if (i == 0)
	{
		if (c == info->obs)
			return (tab[i][j - 1] + 1);
		return (tab[i][j - 1]);
	}
	else if (j == 0)
	{
		if (c == info->obs)
			return (tab[i - 1][j] + 1);
		return (tab[i - 1][j]);
	}
	else
	{
		if (c == info->obs)
			return (tab[i][j - 1] + tab[i - 1][j] - tab[i - 1][j - 1] + 1);
		return (tab[i][j - 1] + tab[i - 1][j] - tab[i - 1][j - 1]);
	}
}

ul	**change(t_minfo info, int len)
{
	int		i;
	int		j;
	ul		**tab;
	char	**arr;

	i = 0;
	j = 0;
	arr = info->map;
	if (!(tab = malloc(sizeof(ul *) * len)))
		return (NULL);
	while (i < len)
	{
		while (arr[j])
		{
			if (j == 0)
				if (!(tab[j] = malloc(sizeof(int) * ft_strlen(arr[j]))))
					return (NULL);
			tab[i][j] = convert(tab, i, j, info, arr[i][j]);
			j++;
		}
		i++;
	}
}
