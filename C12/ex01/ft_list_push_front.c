/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:39:34 by armendes          #+#    #+#             */
/*   Updated: 2020/08/12 17:52:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*element;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	*element = ft_create_elem(data);
	*element->next = *begin_list;
	*begin_list = *element;
}
