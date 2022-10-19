# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:37:43 by jiyoulee          #+#    #+#              #
#    Updated: 2022/02/21 14:43:52 by jiyoulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	$(wildcard *.c)\

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all		=	$(NAME)

%.o :%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(SRCS) -o $(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(OBJS)

re		:	fclean all