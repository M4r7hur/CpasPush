# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 09:53:29 by seciurte          #+#    #+#              #
#    Updated: 2020/08/24 19:07:17 by seciurte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		./srcs/

HEAD_DIR	=		./includes/

SRCS		= 		${SRC_DIR}list_manager.c\
					${SRC_DIR}main.c\
					${SRC_DIR}parse_manager.c\
					${SRC_DIR}solve.c\
					${SRC_DIR}utils.c\

HEAD		=		${HEAD_DIR}libft.h

OBJS		= ${SRCS:.c=.o}

NAME		= bsq

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
