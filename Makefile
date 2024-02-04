# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoreron <7353718@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 16:43:01 by smoreron          #+#    #+#              #
#    Updated: 2024/02/03 16:43:01 by smoreron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make

INCS = push_swap.h
SRC = push_swap.c atoi.c creat_stack.c index.c is_sorted.c list_util.c minim.c push.c rev_rotate.c rotate.c sorted.c split.c swap.c


OBJS = $(SRC:%.c=%.o)

all:			$(NAME)


$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LFLAGS)


%.o:	%.c $(INCS)
				$(CC) -c $< -o $@ $(CFLAGS)

clean:

				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re