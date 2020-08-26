# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 09:53:29 by seciurte          #+#    #+#              #
#    Updated: 2020/08/26 20:53:29 by seciurte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		./srcs/

HEAD_DIR	=		./includes/

SRCS		=		${SRC_DIR}change.c\
					${SRC_DIR}solve.c\
					${SRC_DIR}solve2.c\
					${SRC_DIR}utils.c\
					${SRC_DIR}parse_manager.c\
					${SRC_DIR}split.c\
					${SRC_DIR}main.c

HEAD		=		${HEAD_DIR}lib.h

OBJS		= ${SRCS:.c=.o}

NAME		= BSQ

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${SRCS} -I${HEAD_DIR} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean	fclean re
