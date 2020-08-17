# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 10:40:17 by armendes          #+#    #+#              #
#    Updated: 2020/08/17 11:14:42 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

NAME	= ft_cat

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:
		${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

.PHONY:	all clean fclean
