/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 20:08:43 by armendes          #+#    #+#             */
/*   Updated: 2020/08/26 20:12:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	set_tmp(ul *xtmp, ul x, ul *ytmp, ul y)
{
	*xtmp = x;
	*ytmp = y;
}

void	set_len(ul *lentmp, ul len)
{
	*lentmp = len;
	g_maxlen = len;
}
