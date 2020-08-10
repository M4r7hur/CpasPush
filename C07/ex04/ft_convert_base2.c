/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:14:23 by armendes          #+#    #+#             */
/*   Updated: 2020/08/10 11:32:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		check_base(char *base);

int		len_int(int nbr)
{
	int i;
	long int	nb;

	i = 1;
	nb = 0;
	if (nbr < 0)
		nb = -nbr;
	while (nb / 10 >= 10)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long int 	nb;
	char		*result;

	nb = nbr;
	if (!(result = malloc(sizeof(char) * len_int(nb) + 2)))
		return (NULL);
	if (check_base(base) && nb < 0)
	{
		result += '-';
		nb *= -1;
	}
	if (check_base(base) && nb < ft_strlen(base))
		result += base[nb % ft_strlen(base)];
	if (check_base(base) && nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		result += base[nb % ft_strlen(base)];
	}
	result += '\0';
	return (result);
}
