# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 22:40:30 by cwon              #+#    #+#              #
#    Updated: 2025/08/14 15:32:53 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = \
	Account.hpp
SRC = \
	Account.cpp
MAIN = tests.cpp
OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
