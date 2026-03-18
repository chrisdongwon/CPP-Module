# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 12:44:02 by cwon              #+#    #+#              #
#    Updated: 2026/03/18 14:48:59 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = \
	AForm.hpp \
	Bureaucrat.hpp \
	PresidentialPardonForm.hpp \
	RobotomyRequestForm.hpp \
	ShrubberyCreationForm.hpp
SRC = \
	AForm.cpp \
	Bureaucrat.hpp \
	PresidentialPardonForm.hpp \
	RobotomyRequestForm.hpp \
	ShrubberyCreationForm.hpp
MAIN = main.cpp
OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

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
