# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 09:52:38 by furizalex         #+#    #+#              #
#    Updated: 2025/09/02 17:17:38 by furizalex        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 $(FSAN)
FSAN = -fsanitize=address
RM = rm -rf

SOURCE = megaphone.cpp

OBJECT = $(SOURCE:.cpp=.o)

DEFAULT := \033[1;39m
RESET := \033[0m
GREEN := \033[1;32m
YELLOW := \033[1;33m
CYAN := \033[1;36m

all: $(NAME)

$(NAME): $(OBJECT)
	@echo "\n$(YELLOW)Compiling the megaphone cronk!..$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJECT) -o $(NAME)
	@echo "\n$(GREEN)Successfully compiled the megaphone$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "\n$(CYAN)Cleaning up files...$(RESET)"
	@$(RM) $(OBJECT)

fclean: clean
	@echo "\n$(GREEN)Removing files...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

PHONEY: all clean fclean re