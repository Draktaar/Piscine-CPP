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
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -Wunused -Wunused-const-variable

HEADERS =	Animal.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \
			Cat.hpp \
			Dog.hpp

SRCS =		Animal.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \
			Cat.cpp \
			Dog.cpp \
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