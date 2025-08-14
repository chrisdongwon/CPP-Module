# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 07:49:15 by cwon              #+#    #+#              #
#    Updated: 2025/08/14 15:59:59 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

HEADER = \
	Contact.hpp \
	my_awesome_phonebook.hpp \
	PhoneBook.hpp
SRC = \
	add.cpp \
	Contact.cpp \
	my_awesome_phonebook.cpp \
	PhoneBook.cpp \
	search.cpp \
	util.cpp
MAIN = main.cpp
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
