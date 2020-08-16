/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 10:10:17 by armendes          #+#    #+#             */
/*   Updated: 2020/08/16 10:27:28 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>

int		g_tab[4][4];

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		verif_arg(char *str);
int		**cut(char *str, int x);
int		place(int row, int col, int val);
int		place_row(int *row_l, int row);
int		place_row_r(int *row_r, int row);
int		place_col(int *column_u);
int		place_col_r(int *column_d);

#endif
