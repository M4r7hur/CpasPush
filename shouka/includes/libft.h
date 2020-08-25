/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:46:07 by armendes          #+#    #+#             */
/*   Updated: 2020/08/25 18:50:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_list
{
	long			x;
	long			y;
	struct s_list	*next;
	struct s_list	*next_line;
}					t_list;

typedef struct		s_param
{
	long			xmax;
	long			ymax;
	long			count;
	char			plein;
	char			vide;
	char			obstacle;
	char			*name;
	struct s_list	*next;
}					t_param;

t_list				*create_elem(long x, long y);
void				add_elem(t_list *elem1, t_list *elem2);
void				add_next_line(t_list *elem1, t_list *elem2);
void				put_next_line(t_list *begin_list);
t_list				*list_last(t_list *begin_list);
long				stock(char c, t_param *params, long i, long j);
long				check_nb_col(long fd, long max, t_param *params);
t_param				*get_map_info(long fd, char *name);
t_param				*split_info(char *str, char *name);
void				disp(long xpos, long ypos, t_param *elem, long i);
long				check_obst(long x, long y, t_list *begin_list, long i);
void				solve2(long x, long y, t_param *begin_list, long len);
void				ft_putchar(char c);
long				ft_strlen(char *str);
long				ft_atoi(char *str);

#endif
