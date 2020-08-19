/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:32:50 by armendes          #+#    #+#             */
/*   Updated: 2020/08/19 15:43:22 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge2(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	tmp = *begin_list1;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = begin_list2;
}

void	swap_data2(t_list *tmp1, t_list *tmp2)
{
	void	*tmp;

	tmp = tmp1->data;
	tmp1->data = tmp2->data;
	tmp2->data = tmp;
}

void	ft_list_sort2(t_list **begin_list, int (*cmp)())
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
				swap_data2(tmp1, tmp2);
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	ft_list_merge2(begin_list1, begin_list2);
	ft_list_sort2(begin_list1, cmp);
}
