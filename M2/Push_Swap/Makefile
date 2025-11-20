NAME = push_swap

SRCS_DIR = src
CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)
INCLUDES_DIR = includes

SRCS_MAIN = $(SRCS_DIR)/main.c
SRCS_UTILS = $(SRCS_DIR)/utils/free_and_exit.c \
             $(SRCS_DIR)/utils/lists_fts.c \
             $(SRCS_DIR)/utils/node_creator.c
SRCS_MOVES = $(SRCS_DIR)/moves/push.c \
             $(SRCS_DIR)/moves/rotate.c \
             $(SRCS_DIR)/moves/reverse_rotate.c \
             $(SRCS_DIR)/moves/swap.c
SRCS_SORTING = $(SRCS_DIR)/sorting/add_target.c \
               $(SRCS_DIR)/sorting/sort_3.c \
               $(SRCS_DIR)/sorting/stack_and_sort.c \
               $(SRCS_DIR)/sorting/turk_algorithm.c \
               $(SRCS_DIR)/sorting/rotate_and_push.c
SRCS_VALIDATE = $(SRCS_DIR)/validate/validate_and_parse.c \
                $(SRCS_DIR)/validate/validate_and_parse_utils.c
SRCS_LIBFT = $(SRCS_DIR)/libft/ft_atoi.c \
             $(SRCS_DIR)/libft/ft_split.c \
             $(SRCS_DIR)/libft/ft_strdup.c \
             $(SRCS_DIR)/libft/ft_strlcpy.c \
             $(SRCS_DIR)/libft/ft_strlen.c

SRCS = $(SRCS_MAIN) $(SRCS_UTILS) $(SRCS_MOVES) $(SRCS_SORTING) $(SRCS_VALIDATE) $(SRCS_LIBFT)

INCLUDES = $(INCLUDES_DIR)/push_swap.h

OBJS_DIR = objs
OBJS = $(SRCS:$(SRCS_DIR)/=$(OBJS_DIR)/)
OBJS := $(OBJS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(INCLUDES) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)/utils
	mkdir -p $(OBJS_DIR)/moves
	mkdir -p $(OBJS_DIR)/sorting
	mkdir -p $(OBJS_DIR)/validate
	mkdir -p $(OBJS_DIR)/libft

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
