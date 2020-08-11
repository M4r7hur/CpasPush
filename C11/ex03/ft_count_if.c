/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:35:46 by armendes          #+#    #+#             */
/*   Updated: 2020/08/11 15:40:58 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int i;
	int result;
	int tmp;

	i = 0;
	result = 0;
	while (i < length)
	{
		tmp = (*f)(tab[i]);
		if (tmp != 0)
			result++;
		i++;
	}
	return (result);
}
