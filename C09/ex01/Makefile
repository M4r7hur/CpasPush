# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 09:36:25 by armendes          #+#    #+#              #
#    Updated: 2020/08/10 09:56:01 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/*.c

HEADER	= includes/*.h

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:	${OBJS}
		${CC} ${CFLAGS}

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
