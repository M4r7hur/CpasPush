/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:32:05 by armendes          #+#    #+#             */
/*   Updated: 2020/08/12 19:01:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join(int size, char *dest, char **strs, char *sep)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			dest[k++] = strs[i][j];
		j = -1;
		if (i < size - 1)
		{
			j = -1;
			while (sep[++j])
				dest[k++] = sep[j];
		}
	}
	dest[k] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (size == 0)
		return (dest);
	join(size, dest, strs, sep);
	return (dest);
}
