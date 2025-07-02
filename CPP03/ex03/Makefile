# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 22:45:45 by achu              #+#    #+#              #
#    Updated: 2025/07/02 02:14:59 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		claptrap
CC =		g++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS =	ClapTrap.hpp \
			FragTrap.hpp \
			ScavTrap.hpp \
			DiamondTrap.cpp

SRCS =		ClapTrap.cpp \
			FragTrap.cpp \
			ScavTrap.cpp \
			DiamondTrap.cpp \
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