NAME = gnl_tester

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = get_next_line.c get_next_line_utils.c main_get_next_line.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
