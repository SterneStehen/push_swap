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

LIBFT = libft/libft.a
LIBFT_DIR = libft/
LFLAGS = -L$(LIBFT_DIR) -lft

INCS = push_swap.h
SRC = push_swap.c creat_stack.c index.c is_digit.c is_sorted.c list_util.c minim.c ab_push.c rev_rotate.c rotate.c sorted.c swap.c

OBJS = $(SRC:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LFLAGS)

%.o: %.c $(INCS)
		$(CC) -c $< -o $@ $(CFLAGS) -I$(LIBFT_DIR)

clean:
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
