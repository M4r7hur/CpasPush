/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainArthur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:34:06 by armendes          #+#    #+#             */
/*   Updated: 2020/08/26 14:33:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

#include <stdio.h>

int main(void)
{
	t_minfo *info;

	if (!(info = malloc(sizeof(t_minfo))))
		return (1);
	char *arr[] = {"o....", ".....", ".o..o", ".....", "....o"};
	info->map = arr;
	info->obs = 'o';
	info->nobs = '.';
	info->nbl = 5;
	info->nbc = 5;
	info->fill = 'x';
	info->cursor = 0;
	ul **tab = change(info);
	solve(tab, info, 1);
	/*ul i = 0;
	ul j = 0;
	while (i < info->nbl)
	{
		while (j < info->nbc)
		{
			printf("%lu", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}*/
}
