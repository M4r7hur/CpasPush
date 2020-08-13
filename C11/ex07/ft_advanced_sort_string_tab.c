/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:55:25 by armendes          #+#    #+#             */
/*   Updated: 2020/08/13 19:50:23 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		count;
	int		nb_compare;
	char	*tmp;
	int		i;

	count = 0;
	i = 0;
	while (tab[i + 1])
		i++;
	nb_compare = i;
	while (nb_compare > 0)
	{
		while (count < nb_compare)
		{
			if ((*cmp)(tab[count], tab[count + 1]) > 0)
			{
				tmp = tab[count];
				tab[count] = tab[count + 1];
				tab[count + 1] = tmp;
			}
			count++;
		}
		nb_compare--;
		count = 0;
	}
}
