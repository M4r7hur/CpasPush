/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:47:13 by armendes          #+#    #+#             */
/*   Updated: 2020/08/19 14:49:12 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		size;

	size = 0;
	tmp = begin_list;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_list	*list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*tmp;
	unsigned int	i;

	i = 0;
	tmp = begin_list;
	while (i < nbr)
	{
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	void	*data_tmp;
	int		i;
	int		size;

	i = 0;
	size = list_size(begin_list);
	while (i < size / 2)
	{
		data_tmp = list_at(begin_list, i)->data;
		list_at(begin_list, i)->data = list_at(begin_list, size - i - 1)->data;
		list_at(begin_list, size - i - 1)->data = data_tmp;
		i++;
	}
}
