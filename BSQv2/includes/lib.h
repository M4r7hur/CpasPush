/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:56:46 by seciurte          #+#    #+#             */
/*   Updated: 2020/08/25 20:21:35 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

#include <unistd.h>
#include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	unsigned long ul;
typedef struct			s_minfo
{
	ul		nbl;
	ul		nbc;
	char	**map;
	char	nobs;
	char	obs;
	char	fill;
}						t_minfo;

#endif
