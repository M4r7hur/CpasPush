/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:18:38 by armendes          #+#    #+#             */
/*   Updated: 2020/08/19 16:30:26 by armendes         ###   ########.fr       */
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
