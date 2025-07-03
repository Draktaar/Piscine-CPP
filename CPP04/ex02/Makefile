# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 22:45:45 by achu              #+#    #+#              #
#    Updated: 2025/07/02 17:31:01 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		animal
CC =		g++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS =	AAnimal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp

SRCS =		AAnimal.cpp \
			Cat.cpp \
			Dog.cpp \
			Brain.cpp \
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