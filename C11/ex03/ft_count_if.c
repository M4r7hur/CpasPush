/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:35:46 by armendes          #+#    #+#             */
/*   Updated: 2020/08/11 15:38:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int i;
	int result;
	int tmp;

	i = 0;
	result = 0;
	while (tab[i] != NULL)
	{
		tmp = (*f)(tab[i]);
		if (tmp != 0)
			result++;
		i++;
	}
	return (result);
}
