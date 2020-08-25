/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:19:27 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/25 11:10:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*create_elem(int x, int y)
{
	t_list	*elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->x = x;
	elem->y = y;
	elem->next = NULL;
	elem->next_line = NULL;
	return (elem);
}

void	add_elem(t_list *elem1, t_list *elem2)
{
	elem1->next = elem2;
}

void	add_next_line(t_list *elem1, t_list *elem2)
{
	while (elem1->next != elem2)
	{
		elem1->next_line = elem2;
		elem1 = elem1->next;
	}
}

t_list	*list_last(t_list *begin_list)
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	put_next_line(t_list *begin_list)
{
	t_list	*tmp;
	int		count;
	int		x;

	count = 0;
	tmp = begin_list;
	x = 0;
	while (tmp->x == x)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > 0)
	{
		add_next_line(begin_list, tmp);
		begin_list = tmp;
	}
	count = 0;
}
