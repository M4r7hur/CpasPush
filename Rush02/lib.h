/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 10:48:37 by armendes          #+#    #+#             */
/*   Updated: 2020/08/22 10:51:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIB_H
# define LIB_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_list
{
	int	num;
	int nb_div;
}				t_list;

#endif
