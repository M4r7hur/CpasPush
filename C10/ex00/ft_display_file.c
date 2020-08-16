/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:06:20 by armendes          #+#    #+#             */
/*   Updated: 2020/08/16 11:43:53 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str, int std)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

void	ft_display_file(char *str)
{
	int		file_desc;
	int		bytes_read;
	char	buffer[500];

	file_desc = open(str, O_RDONLY);
	if (file_desc < 0)
	{
		ft_putstr("Cannot read file.\n", 2);
		return ;
	}
	if ((bytes_read = read(file_desc, buffer, 500)))
		ft_putstr(buffer, 1);
	if (close(file_desc) == -1)
		return ;
}

int		main(int ac, char **av)
{
	if (ac > 2)
		ft_putstr("Too many arguments.\n", 2);
	else if (ac < 2)
		ft_putstr("File name missing.\n", 2);
	else
		ft_display_file(av[1]);
	return (0);
}
