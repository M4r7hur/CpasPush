/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:09:15 by armendes          #+#    #+#             */
/*   Updated: 2020/08/27 11:16:24 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

ul	convert(ul **tab, ul i, ul j, t_minfo *info)
{
	if (i == 0 && j == 0)
	{
		if (info->map[i][j] == info->obs)
			return (1);
		return (0);
	}
	else if (i == 0)
	{
		if (info->map[i][j] == info->obs)
			return (tab[i][j - 1] + 1);
		return (tab[i][j - 1]);
	}
	else if (j == 0)
	{
		if (info->map[i][j] == info->obs)
			return (tab[i - 1][j] + 1);
		return (tab[i - 1][j]);
	}
	else
	{
		if (info->map[i][j] == info->obs)
			return (tab[i][j - 1] + tab[i - 1][j] - tab[i - 1][j - 1] + 1);
		return (tab[i][j - 1] + tab[i - 1][j] - tab[i - 1][j - 1]);
	}
}

ul	**change(t_minfo *info)
{
	ul		i;
	ul		j;
	ul		**tab;

	i = 0;
	if (!(tab = malloc(sizeof(ul *) * info->nbl)))
		return (NULL);
	while (i < info->nbl)
	{
		j = 0;
		while (j < info->nbc)
		{
			if (j == 0)
				if (!(tab[i] = malloc(sizeof(ul) * info->nbc)))
					return (NULL);
			tab[i][j] = convert(tab, i, j, info);
			j++;
		}
		i++;
	}
	return (tab);
}

void	free_tab(ul **tab, t_minfo *minfo)
{
	ul i;

	i = 0;
	while (i < minfo->nbl)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
