# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 20:46:13 by achu              #+#    #+#              #
#    Updated: 2025/08/06 08:57:06 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		btc
CC =		c++
CFLAGS =	-Wall -Wextra -std=c++98 -Wunused -Wunused-const-variable

HEADERS =	BitcoinExchange.h

SRCS =		BitcoinExchange.cpp \
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