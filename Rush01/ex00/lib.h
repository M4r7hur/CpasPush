/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 10:10:17 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 14:42:57 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

int		g_tab[4][4];

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		verif_arg(char *str);
char	**cut(char *str, int x);
int		place(int row, int col, int val);
int		place_row(int *rowL, int row);
int		place_row_rev(int *rowR, int row);
int		place_col(int *columnU);
int		place_col_rev(int *columnD);

#endif
