# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 09:53:29 by seciurte          #+#    #+#              #
#    Updated: 2020/08/24 09:54:52 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		./srcs/

HEAD_DIR	=		./includes/

SRCS		= 		${SRC_DIR}check.c\
					${SRC_DIR}main.c\
					${SRC_DIR}init_nb.c\
					${SRC_DIR}utils.c\
					${SRC_DIR}parse.c\
					${SRC_DIR}parse2.c\
					${SRC_DIR}open_dico.c

HEAD		=		${HEAD_DIR}header.h

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

.c.o:
			${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I${HEAD_DIR} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean	fclean re
