# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 07:42:56 by cwon              #+#    #+#              #
#    Updated: 2025/10/13 13:57:45 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex04

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Replacer.hpp
SRC = Replacer.cpp
MAIN = main.cpp
OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

TEST_FILES = \
	expected* \
	file*

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TEST_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
