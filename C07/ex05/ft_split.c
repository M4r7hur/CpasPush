/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:36:13 by armendes          #+#    #+#             */
/*   Updated: 2020/08/11 10:11:40 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int		nb_mall(char *str, char *charset)
{
	int i;
	int j;
	int result;

	i = 0;
	j = 0;
	result = 0;
	while (str[i])
	{
		printf("B");
		if (check_charset(str[i], charset) == 1)
			result++;
		i++;
	}
	printf("%d", result);
	return (result);
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
	if (!(result = (char **) malloc(sizeof(char *) * nb_mall(str, charset) + 1)))
		return (NULL);
	while (str[i + j])
	{
		printf("a");
		if (check_charset(str[i + j], charset) == 1)
		{
			if (!(result[k] = malloc(sizeof(char) * j + 1)))
				return (NULL);
			ft_strncat(result[k], &str[i], j);
			i = i + j;
			j = 0;
			k++;
		}
		else
			j++;
	}
	result[k] = "0";
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
