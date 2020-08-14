/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:30:03 by armendes          #+#    #+#             */
/*   Updated: 2020/08/14 16:36:23 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = begin_list;
	tmp2 = tmp->next;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp->next;
		(*free_fct)(tmp->data);
		free(tmp);
		tmp = tmp2;
	}
}
