/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:25:20 by armendes          #+#    #+#             */
/*   Updated: 2020/08/17 12:41:05 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*elem;
	t_list	*tmp;
	t_list	*tmp2;

	if (*begin_list)
	{
		elem = *begin_list;
		tmp = elem->next;
		tmp2 = tmp->next;
		elem->next = NULL;
		while (tmp2)
		{
			tmp->next = elem;
			elem = tmp;
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		tmp->next = elem;
		*begin_list = tmp;
	}
}
