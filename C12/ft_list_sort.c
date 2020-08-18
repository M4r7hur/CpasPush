/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:08:33 by armendes          #+#    #+#             */
/*   Updated: 2020/08/18 18:45:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_data(t_list *tmp1, t_list *tmp2)
{
	void	*tmp;

	tmp = tmp1->data;
	tmp1->data = tmp2->data;
	tmp2->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
				swap_data(tmp1, tmp2);
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
}
