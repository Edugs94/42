NAME = libftprintf.a

SRC = ft_printf.c print_functions.h hex_functions.h

LIBFT_DIR = libft/
LIBFT_NAME = libft.a

HEADER = ft_printf.h

OBJS = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)

FLAGS = -Wall -Wextra -Werror -MMD

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	ar -rcs $(NAME)	$(OBJS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME) all

%.o:%.c Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean re fclean all
