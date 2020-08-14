/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:02:24 by armendes          #+#    #+#             */
/*   Updated: 2020/08/14 11:49:53 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);

int main(void)
{
	t_list *element;
	t_list *list = NULL;

	char *str = "bonjour";
	element = ft_create_elem(str);
	printf("1%s\n", element->data);

	char *str2 = "bonjour2";
	ft_list_push_front(&list, str2);
	printf("2%s", list->data);

	char *str3 = "bonjour3";
	ft_list_push_front(&list, str3);
	printf("%s", list->data);

	char *str4 = "bonjour4";
	ft_list_push_front(&list, str4);
	printf("%s\n", list->data);

	printf("3%d\n", ft_list_size(list));

	t_list *tmp = ft_list_last(list);
	printf("4%s\n", tmp->data);

	char *str5 = "bonjour5";
	ft_list_push_back(&list, str5);
	printf("5%s", list->data);
	t_list *tmp2 = ft_list_last(list);
	printf("%s\n", tmp2->data);


}
