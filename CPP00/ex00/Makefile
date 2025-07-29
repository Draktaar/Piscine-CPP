# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 13:58:33 by achu              #+#    #+#              #
#    Updated: 2025/07/29 10:55:00 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		megaphone
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -Wunused -Wunused-const-variable

SRCS =	megaphone.cpp

OBJS =	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re