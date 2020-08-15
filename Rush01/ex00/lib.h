/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 10:10:17 by armendes          #+#    #+#             */
/*   Updated: 2020/08/15 11:06:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		verif_arg(char *str);
char	**cut(char *str, int x);
int		place(int row, int col, int val);
int		place_row(char **rows, int row);
int		place_row_rev(char **rows, row);
int		place_col(char **columns);
int		place_col_rev(char **columns);

#endif
