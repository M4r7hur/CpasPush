/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:56:46 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/26 12:21:11 by seciurte         ###   ########.fr       */
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
ul			matoi(char *str);
ul			len(char *str);

#endif
