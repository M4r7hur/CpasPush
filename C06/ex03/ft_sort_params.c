/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:42:39 by armendes          #+#    #+#             */
/*   Updated: 2020/08/08 15:14:50 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int		count;
	int		nb_compare;
	char	*tmp;

	count = 0;
	nb_compare = argc - 1;
	while (nb_compare-- > 0)
	{
		while (count++ < nb_compare)
		{
			if (ft_strcmp(argv[count], argv[count + 1]) > 0)
			{
				tmp = argv[count];
				argv[count] = argv[count + 1];
				argv[count + 1] = tmp;
			}
		}
		count = 0;
	}
	while (++count < argc)
	{
		ft_putstr(argv[count]);
		ft_putchar('\n');
	}
}
