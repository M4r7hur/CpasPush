/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:39:34 by armendes          #+#    #+#             */
/*   Updated: 2020/08/14 10:50:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	else
	{
		elem = ft_create_elem(data);
		elem->next = *begin_list;
		*begin_list = elem;
	}
}
