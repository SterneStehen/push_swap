
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make

INCS = push_swap.h
SRCS = push_swap.c count.c creat_stack.c find.c intdex.c list.c push_swap.c push.c rev_rotate.c rotate.c sort.c split.c swap.c 

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)


all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LFLAGS)

$(OBJ_DIR):
				mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o:	%.c $(INCS)
				$(CC) -c $< -o $@ $(CFLAGS)



clean:
				$(RM) $(OBJ_DIR)
				 $(MAKE) clean

fclean: 		clean
				$(RM) $(NAME)
				$(MAKE) fclean

re:				fclean all

.PHONY: all clean fclean re bonus
