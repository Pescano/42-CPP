# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 15:52:16 by paescano          #+#    #+#              #
#    Updated: 2023/12/08 16:04:49 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragTrap

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

CPPFILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

SRCS = ${addprefix $(SRC_DIR), $(CPPFILES)}
OBJECTS = ${patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.opp, $(SRCS)}

HEADERS = includes/ClapTrap.hpp includes/ScavTrap.hpp includes/FragTrap.hpp
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