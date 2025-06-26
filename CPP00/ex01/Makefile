# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 00:50:11 by achu              #+#    #+#              #
#    Updated: 2025/06/26 13:41:41 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		phonebook
CC =		g++
CFLAGS =	-Wall -Wextra -std=c++98

HEADERS =	PhoneBook.hpp \
			Contact.hpp \

SRCS =		PhoneBook.cpp \
			Contact.cpp \
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