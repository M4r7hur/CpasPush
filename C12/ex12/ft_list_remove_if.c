/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:56:56 by armendes          #+#    #+#             */
/*   Updated: 2020/08/18 17:50:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*tmp;

	while (*begin_list && ((*cmp)((*begin_list)->data, data_ref)) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(tmp->data);
		free(tmp);
	}
	list_ptr = *begin_list;
	while (list_ptr && list_ptr->next)
	{
		if (((*cmp)(list_ptr->next->data, data_ref)) == 0)
		{
			tmp = list_ptr->next;
			list_ptr->next = tmp->next;
			(*free_fct)(tmp->data);
			free(tmp);
		}
		list_ptr = list_ptr->next;
	}
}
