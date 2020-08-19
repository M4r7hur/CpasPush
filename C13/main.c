/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:19:22 by armendes          #+#    #+#             */
/*   Updated: 2020/08/19 18:25:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

t_btree	*b_tree_create_node(void *item);

int		main(void)
{

	printf("Create node\n");
	printf("--------------------------\n");
	char *str = "bonjour";
	t_btree *tmp = b_tree_create_node(str);
	printf("%s\n", tmp->item);
	printf("\n");
	printf("\n");
}
