# --- Variables ---

NAME = libftprintf.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Comandos
RM = rm -f
AR = ar rcs

# --- Archivos ---

SRCS = ft_printf.c  utils_01.c utils_02.c

OBJS = $(SRCS:.c=.o)

HEADERS = libftprintf.h libft.h

# --- Reglas ---

# make solo
all: $(NAME)

# dependencias a .o
$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@echo "Librería obligatoria creada."


# Regla genérica para compilar cualquier .c en un .o.
# Se ejecutará de nuevo si el .c, el .h o el propio Makefile cambian.
%.o: %.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

# 'make clean': Borra solo *.o
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Archivos .o eliminados."

fclean: clean
	@$(RM) $(NAME)
	@echo "Todo limpio."

re: fclean all

.PHONY: all clean fclean re bonus
