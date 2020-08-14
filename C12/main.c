/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:02:24 by armendes          #+#    #+#             */
/*   Updated: 2020/08/14 11:06:21 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);

int main(void)
{
	t_list *element;
	t_list *list = NULL;

	char *str = "bonjour";
	element = ft_create_elem(str);
	printf("%s\n", element->data);

	char *str2 = "bonjour2";
	ft_list_push_front(&list, str2);
	printf("%s", list->data);

	char *str3 = "bonjour3";
	ft_list_push_front(&list, str3);
	printf("%s", list->data);

	char *str4 = "bonjour4";
	ft_list_push_front(&list, str4);
	printf("%s\n", list->data);

	printf("%d\n", ft_list_size(list));

	t_list *tmp = ft_list_last(list);
	printf("%s\n", tmp->data);
}
