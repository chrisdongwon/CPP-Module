# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 12:44:02 by cwon              #+#    #+#              #
#    Updated: 2026/03/19 12:15:01 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

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
	Bureaucrat.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp
MAIN = main.cpp
OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

FCLEAN_FILES = *_shrubbery

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TEST_FILES)

fclean: clean
	rm -f $(NAME)
	rm -f $(FCLEAN_FILES)

re: fclean all

.PHONY: all clean fclean re
