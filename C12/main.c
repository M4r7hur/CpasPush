/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:02:24 by armendes          #+#    #+#             */
/*   Updated: 2020/08/18 13:54:21 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

void	free(void *data)
{
	(void)data;
}

void	print(void *data)
{
	printf("%s ", (char *)data);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

int main(void)
{
	t_list *element;
	t_list *list = NULL;

	printf("Create elem\n");
	printf("-----------------------------\n");
	char *str = "bonjour";
	element = ft_create_elem(str);
	printf("%s\n", element->data);
	printf("\n");

	printf("Push front\n");
	printf("-----------------------------\n");
	char *str2 = "bonjour2";
	ft_list_push_front(&list, str2);
	printf("%s", list->data);
	char *str3 = "bonjour3";
	ft_list_push_front(&list, str3);
	printf("%s", list->data);
	char *str4 = "bonjour4";
	ft_list_push_front(&list, str4);
	printf("%s\n", list->data);
	printf("\n");

	printf("List size\n");
	printf("-----------------------------\n");
	printf("%d\n", ft_list_size(list));
	printf("\n");

	printf("List last\n");
	printf("-----------------------------\n");
	t_list *tmp = ft_list_last(list);
	printf("%s\n", tmp->data);
	printf("\n");

	printf("Push back\n");
	printf("-----------------------------\n");
	char *str5 = "bonjour5";
	ft_list_push_back(&list, str5);
	printf("%s", list->data);
	t_list *tmp2 = ft_list_last(list);
	printf("%s\n", tmp2->data);
	printf("\n");

	printf("Push strs\n");
	printf("-----------------------------\n");
	char *strs[4] = {"bonjour", "les", "amis", "hello"};
	tmp = ft_list_push_strs(4, strs);
	printf("%s ", tmp->data);
	printf("%s ", tmp->next->data);
	printf("%s ", tmp->next->next->data);
	printf("%s\n", tmp->next->next->next->data);
	printf("\n");

	printf("List clear\n");
	printf("-----------------------------\n");
	ft_list_clear(tmp, &free);
	printf("%s\n", tmp->data);
	printf("\n");

	printf("List at\n");
	printf("-----------------------------\n");
	t_list	*list2;
	list2 = ft_list_at(tmp, 1);
	printf("%s\n", list2->data);
	printf("\n");

	printf("List reverse\n");
	printf("-----------------------------\n");
	ft_list_reverse(&tmp);
	printf("%s ", tmp->data);
	printf("%s ", tmp->next->data);
	printf("%s ", tmp->next->next->data);
	printf("%s\n", tmp->next->next->next->data);
	printf("\n");

	printf("List foreach\n");
	printf("-----------------------------\n");
	ft_list_foreach(tmp, &print);
	printf("\n");
	printf("\n");

	printf("List foreach if\n");
	printf("-----------------------------\n");
	char	*data_ref = "amis";
	ft_list_foreach_if(tmp, &print, data_ref, &ft_strcmp);
	printf("\n");
	printf("\n");

	printf("List find\n");
	printf("-----------------------------\n");
	t_list	*res = ft_list_find(tmp, data_ref, &ft_strcmp);
	printf("%s\n", res->data);
	printf("\n");

}
