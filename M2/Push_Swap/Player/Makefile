
NAME = push_swap_game

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRCS = 	node_creator.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		player_push_swap.c

HDRS = push_swap.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HDRS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re