# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 16:49:28 by armendes          #+#    #+#              #
#    Updated: 2020/08/13 14:32:14 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= do_op.c put.c op.c

NAME	= do-op

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} ${NAME}

re:			clean all

.PHONY:		all clean fclean re
