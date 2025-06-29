# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 01:55:14 by achu              #+#    #+#              #
#    Updated: 2025/06/29 01:55:50 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		zombie
CC =		g++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS =	Zombie.hpp

SRCS =		zombieHorde.cpp \
			Zombie.cpp \
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