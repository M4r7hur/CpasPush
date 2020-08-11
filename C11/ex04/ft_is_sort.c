/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:39:26 by armendes          #+#    #+#             */
/*   Updated: 2020/08/11 16:34:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int croissant;
	int decroissant;

	i = 0;
	croissant = 0;
	decroissant = 0;
	if (length == 0 || length == 1)
		return (1);
	while (i < length)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			croissant++;
		if ((*f)(tab[i], tab[i + 1]) > 0)
			decroissant++;
		else
		{
			croissant++;
			decroissant++;
		}
		i++;
	}
	if (croissant == length || decroissant == length)
		return (1);
	return (0);
}
