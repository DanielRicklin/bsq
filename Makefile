# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dricklin <dricklin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 17:15:19 by dricklin          #+#    #+#              #
#    Updated: 2019/07/22 21:43:53 by dricklin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOSS	=	srcs/
SRCS	=	${DOSS}main.c ${DOSS}ft_split.c ${DOSS}ft_utils.c
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	bsq
CC		=	gcc
RM		=	rm -f
HEADER	=	includes/ft_bsq.h

.c.o:
			${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bsq