# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 09:36:25 by armendes          #+#    #+#              #
#    Updated: 2020/08/10 10:31:53 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard srcs/*.c)

HEADER	= includes/ft.h

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

.c.o:		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
