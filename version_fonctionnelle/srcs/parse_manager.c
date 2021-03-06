/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:58:07 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/25 15:10:18 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		stock(char c, t_param *params, long *count, long i, long j)
{
	t_list *elem;
	t_list *elem2;

	if (c == params->vide)
		(*count)++;
	else if (c == params->obstacle)
	{
		if (params->next == NULL)
		{
			elem = create_elem(i, j);
			params->next = elem;
		}
		else
		{
			elem2 = create_elem(i, j);
			add_elem(list_last(params->next), elem2);
		}
	}
	else
		return (1);
	return (0);
}

long			check_nb_col(long fd, long max, t_param *params)
{
	long		i;
	long		j;
	long		len;
	char	c;
	long		count;

	count = 0;
	i = -1;
	while (++i < max)
	{
		j = 0;
		while (read(fd, &c, 1) && c != '\n')
		{
			if (stock(c, params, &count, i, j))
				return (1);
			j++;
		}
		if (i == 0)
			len = j;
		else if (j != len)
			return (1);
	}
	if (count == 0)
		return (1);
	params->ymax = len;
	return (0);
}

t_param		*get_map_info(long fd, char *name)
{
	char		c;
	char		info[500];
	long			i;
	t_param		*params;

	i = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		info[i] = c;
		i++;
	}
	info[i] = '\0';
	params = split_info(info, name);
	if (check_nb_col(fd, params->xmax, params))
	{
		write(2, "map error\n", 10);
		return (NULL);
	}
	if (close(fd) == -1)
		return (NULL);
	return (params);
}

t_param		*split_info(char *str, char *name)
{
	t_param		*info;

	if (!(info = malloc(sizeof(t_param))))
		return (NULL);
	info->name = name;
	info->plein = str[ft_strlen(str) - 1];
	info->obstacle = str[ft_strlen(str) - 2];
	info->vide = str[ft_strlen(str) - 3];
	str[ft_strlen(str) - 3] = '\0';
	info->xmax = ft_atoi(str);
	info->ymax = 0;
	info->next = NULL;
	return (info);
}
