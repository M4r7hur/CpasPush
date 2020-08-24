/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:46:07 by armendes          #+#    #+#             */
/*   Updated: 2020/08/24 18:24:07 by seciurte         ###   ########.fr       */
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
	int				xmax;
	int				ymax;
	char			plein;
	char			vide;
	char			obstacle;
	char			*name;
	struct s_list	*next;
}				t_param;

t_list		*create_elem(int x, int y);
void		add_elem(t_list *elem1, t_list *elem2);
void		add_next_line(t_list *elem1, t_list *elem2);
t_list		*list_last(t_list *begin_list);
int			stock(char c, t_param *params, int *count, int i, int j);
int			check_nb_col(int fd, int max, t_param *params);
t_param		*get_map_info(int fd, char *name);
t_param		*split_info(char *str, char *name);
void		disp(int xpos, int ypos, t_param *elem, int i);
int			check_obst(int x, int y, t_list *begin_list, int i);
void		solve(int xbord, int ybord, t_param *begin_list, int i);
void		ft_putchar(char c);
int			ft_strlen(char *str);
int			ft_atoi(char *str);


#endif
