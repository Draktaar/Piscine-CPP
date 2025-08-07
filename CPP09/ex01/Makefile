# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 20:46:13 by achu              #+#    #+#              #
#    Updated: 2025/08/07 00:05:21 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		RPN
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -Wunused -Wunused-const-variable

HEADERS =	RPN.h

SRCS =		RPN.cpp \
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