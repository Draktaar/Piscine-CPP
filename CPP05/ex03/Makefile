# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 15:00:21 by achu              #+#    #+#              #
#    Updated: 2025/07/08 17:04:26 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		bureaucrat
CC =		g++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS =	Bureaucrat.hpp \
			Intern.hpp \
			AForm.hpp \
			PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp \
			ShrubberyCreationForm.hpp \
			

SRCS =		Bureaucrat.cpp \
			Intern.cpp \
			AForm.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			main.cpp

OBJS =	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(HEADERS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re