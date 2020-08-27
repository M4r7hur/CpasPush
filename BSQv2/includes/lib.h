/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:36:45 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/27 10:32:02 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	unsigned long	ul;

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

void					ft_putchar(char c);
ul						matoi(char *str);
ul						len(char *str);
ul						convert(ul **tab, ul i, ul j, t_minfo *info);
ul						**change(t_minfo *info);
void					solve(ul **tab, t_minfo *info, ul len);
void					set_tmp(ul *xtmp, ul x, ul *ytmp, ul y);
void					set_len(ul *lentmp, ul len);
t_minfo					*get_minfo_file(char *name);
ul						get_map_info(t_minfo *minfo, int fd, char *name);
void					reset_cursor(int fd, char *name);
char					*get_raw_map(int fd, char *name);
int						check_charset(char c, char *charset);
int						nb_mall(char *str, char *charset);
int						len_str(char *str, char *charset, int nb);
void					split(char **result, char *str, char *charset);
char					**msplit(char *str, char *charset);
void					disp(ul x, ul y, ul len, t_minfo *info);
int						check_valid(ul **tab, ul x, ul y, ul len);
ul						check_maperr(char **str, t_minfo *minfo);
void					free_malloc(t_minfo *minfo);

#endif
