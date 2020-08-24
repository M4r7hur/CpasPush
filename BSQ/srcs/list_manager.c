/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:19:27 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/24 10:49:18 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*create_elem(int x, int y)
{
	t_list	*elem;

	if (!(elem = malloc(sizeof(t_list) * 1)))
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
	elem1->next_line = elem2->next;
}
