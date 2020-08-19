/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:51:15 by armendes          #+#    #+#             */
/*   Updated: 2020/08/19 15:31:40 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_push_front(t_list **begin_list, void *data)
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

void	swap_data_(t_list *tmp1, t_list *tmp2)
{
	void	*tmp;

	tmp = tmp1->data;
	tmp1->data = tmp2->data;
	tmp2->data = tmp;
}

void	list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		loop;

	if (!(*begin_list) || !((*begin_list)->next))
		return ;
	loop = 1;
	while (loop)
	{
		loop = 0;
		tmp1 = *begin_list;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if ((*cmp)(tmp1->data, tmp2->data) > 0)
			{
				loop = 1;
				swap_data_(tmp1, tmp2);
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	list_push_front(begin_list, data);
	list_sort(begin_list, cmp);
}
