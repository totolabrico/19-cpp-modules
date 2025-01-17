# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 15:33:53 by tbarbe            #+#    #+#              #
#    Updated: 2024/02/15 14:39:47 by tbarbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	RPN

SRCS	=	*.cpp

CC		=	c++

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		${NAME}			

${NAME}:	
			${CC} ${CFLAGS} ${SRCS} -o ${NAME} 

clean:
			
fclean: 	clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
