/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:38:34 by armendes          #+#    #+#             */
/*   Updated: 2020/08/09 17:08:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = 0;
	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		if (!(tab[i].str = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return (NULL);
		tab[i].str = av[i];
		if (!(tab[i].copy = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return (NULL);
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
