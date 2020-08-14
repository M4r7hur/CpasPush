/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:02:24 by armendes          #+#    #+#             */
/*   Updated: 2020/08/14 10:31:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

int main(void)
{
	t_list *element;

	char *str = "bonjour";
	element = ft_create_elem(str);
	printf("%s\n", element->data);
	
	char *str2 = "bonjour2";
	ft_list_push_front(*element, str2);
	printf("%s", element->data);
}
