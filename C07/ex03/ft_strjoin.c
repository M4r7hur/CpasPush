/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:32:05 by armendes          #+#    #+#             */
/*   Updated: 2020/08/09 11:29:52 by armendes         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*join(int size, char *dest, char **strs, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size - 1)
	{
		ft_strcat(dest, strs[i]);
		ft_strcat(dest, sep);
		i++;
	}
	ft_strcat(dest, strs[i]);
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

#include <stdio.h>
#include <unistd.h>
int main(void)
{
	char *strs[] = {"bonjour", "les", "amis"};
	char *sep = " ";
	printf("%s", ft_strjoin(3, strs, sep));
}
