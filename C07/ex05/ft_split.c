/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:36:13 by armendes          #+#    #+#             */
/*   Updated: 2020/08/10 14:01:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int 	i;
	int 	j;
	int		k;
	char	**result;

	i = 0;
	j = 0;
	k = 0;
	result = NULL;
	while (str[i + j])
	{
		if (check_charset(str[i + j], charset) == 1)
		{
			ft_strncat(result[k], &str[i], j);
			i = i + j;
			j = 0;
			k++;
		}
		else
			j++;
	}
	return (result);
}

#include <stdio.h>

int main(void)
{
	char *str = "bonjour";
	char *charset = "o";
	char **result = ft_split(str, charset);

	int i = 0;
	while (i < 1)
	{
		printf("%s ", result[i]);
		i++;
	}
}
