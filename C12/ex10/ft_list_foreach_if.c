/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:33:40 by armendes          #+#    #+#             */
/*   Updated: 2020/08/18 13:49:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr->next)
	{
		if (((*cmp)(list_ptr->data, data_ref)) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
	if (((*cmp)(list_ptr->data, data_ref)) == 0)
		(*f)(list_ptr->data);
}
