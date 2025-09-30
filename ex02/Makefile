# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 16:59:50 by alechin           #+#    #+#              #
#    Updated: 2025/09/30 10:29:45 by alechin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CXX = g++
FSAN = -fsanitize=address
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 $(FSAN)
RM = rm -rf

SOURCE = \
	tests.cpp		\
	Account.cpp		\

HEADER = \
	Account.hpp		\

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