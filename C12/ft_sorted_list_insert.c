/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:51:15 by armendes          #+#    #+#             */
/*   Updated: 2020/08/19 15:05:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;
	t_list	*elem;

	tmp = *begin_list;
	elem = ft_create_elem(data);
	if (!(*begin_list))
	{
		*begin_list = elem;
		return ;
	}
	while (tmp->next)
	{
		if ((*cmp)(tmp->data, elem->data) > 0)
		{
			elem->next = tmp->next;
			tmp->next = elem->next;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = elem;
}
