/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:46:07 by armendes          #+#    #+#             */
/*   Updated: 2020/08/24 13:44:18 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list
{
	int				x;
	int				y;
	struct s_list	*next;
	struct s_list	*next_line;
}				t_list;

typedef struct	s_param
{
	int				max;
	char			plein;
	char			vide;
	char			obstacle;
	char			*name;
	struct s_list	*next;
}				t_param;

int				ver_x(int i, int x, int len);
int				ver_y(int j, int y, int len);
void			disp(int x, int y, t_param *e, int len);
int				check_obst(int x, int y, t_list *begin_list, int len);
void			solve(int xbord, int ybord, t_param *begin_list, int len);


#endif
