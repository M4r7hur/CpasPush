/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:52:46 by armendes          #+#    #+#             */
/*   Updated: 2020/08/14 12:50:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;
	t_list	*elem2;

	i = 1;
	elem = ft_create_elem(strs[0]);
	while (i < size)
	{
		elem2 = ft_create_elem(strs[i]);
		elem2->next = elem;
		elem = elem2;
		i++;
	}
	return (elem);
}
