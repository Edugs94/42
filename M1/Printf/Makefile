NAME = libftprintf.a

SRC = ft_printf.c ft_print_char.c ft_print_integer.c ft_print_pointer.c ft_print_string.c ft_print_unsigned.c ft_print_hex.c

LIBFT_DIR = libft
LIBFT_NAME = libft.a

HEADERS = ft_printf.h

OBJS = $(SRC:.c=.o)
LIBFT_OBJS = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_printf.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

DEPS = $(SRC:.c=.d)

FLAGS = -Wall -Wextra -Werror -g -MMD

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) all
	ar -xv $(LIBFT_DIR)/$(LIBFT_NAME)
	ar -rcs $(NAME)	$(OBJS) $(LIBFT_OBJS)

%.o:%.c $(HEADERS) Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS) $(LIBFT_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean re fclean all
