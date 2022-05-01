# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 19:55:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/05/01 14:43:07 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
SRCS = 	get_next_line.c \
		get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $^

debug:
	$(CC) -g $(SRCS) main.c

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re