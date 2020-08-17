/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:38:00 by armendes          #+#    #+#             */
/*   Updated: 2020/08/17 11:17:37 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str, int nb)
{
	while (*str)
	{
		write(nb, str, 1);
		str++;
	}
}

void	ft_display_file(char *str)
{
	int		file_desc;
	int		bytes_read;
	char	buffer[300];

	file_desc = open(str, O_RDONLY);
	if (file_desc < 0)
	{
		ft_putstr("Cannot read file.\n", 2);
		return ;
	}
	if ((bytes_read = read(file_desc, buffer, 300)))
		ft_putstr(buffer, 1);
	if (close(file_desc) == -1)
		return ;
}

void	cat(char *str)
{
	if (open(str, O_DIRECTORY) > 0)
	{
		ft_putstr("DIRECTORY", 2);
		return ;
	}
	else
		ft_display_file(str);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i > ac)
		{
			cat(av[i]);
		}
	}
	else
		ft_putstr("Error\n", 2);
}
