# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 15:00:21 by achu              #+#    #+#              #
#    Updated: 2025/07/29 10:54:50 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		rpg
CC =		c++
CFLAGS =	-Wall -Wextra -std=c++98 -Wunused -Wunused-const-variable

HEADERS =	sources/IMateriaSource.hpp \
			sources/MateriaSource.hpp \
			sources/AMateria.hpp \
			sources/Cure.hpp \
			sources/Ice.hpp \
			sources/ICharacter.hpp \
			sources/Character.hpp

SRCS =		sources/MateriaSource.cpp \
			sources/AMateria.cpp \
			sources/Cure.cpp \
			sources/Ice.cpp \
			sources/Character.cpp \
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