/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:56:46 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 13:52:50 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	unsigned long ul;

typedef struct			s_minfo
{
	ul		nbl;
	ul		nbc;
	ul		cursor;
	char	**map;
	char	nobs;
	char	obs;
	char	fill;
}						t_minfo;

t_minfo		*get_entry_from_stdin();
t_minfo		*get_map_info(char *buf);
void		get_map(t_minfo *minfo, char *buf);
void		get_line(t_minfo *minfo, ul i, ul size);
void		free_mall(t_minfo *minfo, ul i);
void		ft_putchar(char c);
ul			matoi(char *str);
ul			len(char *str);
ul			convert(ul **tab, ul i, ul j, t_minfo *info);
ul			**change(t_minfo *info);
void		solve(ul **tab, t_minfo *info, ul len);

#endif
