# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 15:22:16 by paescano          #+#    #+#              #
#    Updated: 2023/11/17 17:19:36 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRC = megaphone.cpp

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

all: ${NAME}

${NAME}: ${SRC}
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@${CC} ${CFLAGS} ${SRC} -o ${NAME}
	@echo $(G)Finished Compiling of [$(NAME)]$(X)

clean:
	@echo $(R)Removed objects$(X)
	
fclean: clean
	@${RM} ${NAME}
	@echo $(R)Removed following executable: [$(NAME)]$(X)

re: fclean all

.PHONY:	all clean fclean re