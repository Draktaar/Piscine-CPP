# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 22:45:45 by achu              #+#    #+#              #
#    Updated: 2025/07/01 23:17:38 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		claptrap
CC =		g++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS =	ClapTrap.hpp

SRCS =		ClapTrap.cpp \
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