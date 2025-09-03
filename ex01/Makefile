# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 12:33:02 by furizalex         #+#    #+#              #
#    Updated: 2025/09/02 15:54:28 by furizalex        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CXX = g++
FSAN = -fsanitize=address
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 $(FSAN)
RM = rm -rf

SOURCE = \
	main.cpp		\
	print.cpp		\
	contact.cpp		\
	phonebook.cpp	\

HEADER = \
	contact.hpp		\
	phonebook.hpp	\

OBJECT = $(SOURCE:.cpp=.o)

DEFAULT := \033[1;39m
RESET := \033[0m
GREEN := \033[1;32m
YELLOW := \033[1;33m
CYAN := \033[1;36m

all: $(NAME)

$(NAME): $(OBJECT)
	@printf "\n$(YELLOW)Compiling phonebook...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(OBJECT) -o $(NAME)
	@printf "\n$(GREEN)Successfully compiled phonebook!$(RESET)\n"

%.o: %.cpp $(HEADER)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@printf "\n$(CYAN)Cleaning object files...$(RESET)\n"
	@$(RM) $(OBJECT)

fclean: clean
	@printf "\n$(GREEN)Removing binary...$(RESET)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re