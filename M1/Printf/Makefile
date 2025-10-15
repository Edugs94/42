NAME = libftprintf.

SRC = ft_printf.c utils_01.h utils_02.h \

LIBFT_DIR = libft/

LIBFT_NAME = libft.a

HEADER = ft_printf.h

OBJS = $(SRC:.c=.o)

DEPS = $(SRC: .c=.d)

FLAGS = -Wall -Wextra -Werror -MMD

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME) all

%.o:%.c Makefile
	cc $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) $(LIBFT_NAME) fclean

re: fclean all

.PHONY: clean re fclean all
