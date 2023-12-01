# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:46:45 by paescano          #+#    #+#              #
#    Updated: 2023/11/30 11:35:55 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

SRC_DIR = src/
OBJ_DIR = obj/

CPPFILES = main.cpp Harl.cpp

SRCS = ${addprefix $(SRC_DIR), $(CPPFILES)}
OBJECTS = ${patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.opp, $(SRCS)}

HEADERS = includes/Harl.hpp
INCLUDES =	-I ./includes

all: ${NAME}

${NAME}: $(HEADERS) ${OBJECTS}
	@echo $(G)Created Objects folder$(X)
	@echo $(G)Finished Compiling of [$(CPPFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@${CC} ${CFLAGS} $(INCLUDES) ${OBJECTS} -o ${NAME}
	@echo $(G)Finished Compiling of [$(NAME)]$(X)

$(OBJ_DIR)%.opp: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo $(R)Removed objects folder$(X)

fclean: clean
	@${RM} ${NAME}
	@echo $(R)Removed following executable: [$(NAME)]$(X)

re: fclean all

.PHONY:	all clean fclean re