# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 15:00:21 by achu              #+#    #+#              #
#    Updated: 2025/07/25 00:54:38 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		convert
CC =		g++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS =	Serializer.h \
			Data.h

SRCS =		Serializer.cpp \
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