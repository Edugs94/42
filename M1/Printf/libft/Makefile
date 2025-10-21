# --- Variables ---

NAME = libft.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Comandos
RM = rm -f
AR = ar rcs

# --- Archivos ---

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
             ft_lstsize_bonus.c ft_lstlast_bonus.c \
             ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
             ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADERS = libft.h

# --- Reglas ---

# make solo
all: $(NAME)

# dependencias a .o
$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@echo "Librería obligatoria creada."


# La regla 'bonus' depende de que exista un archivo oculto '.bonus'.
bonus: .bonus

# Para crear el .bonus, necesita todos los archivos objeto (obligatorios y bonus).
.bonus: $(OBJS) $(OBJS_BONUS)

	@$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@touch .bonus
	@echo "Librería con bonus creada."

# Regla genérica para compilar cualquier .c en un .o.
# Se ejecutará de nuevo si el .c, el .h o el propio Makefile cambian.
%.o: %.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

# 'make clean': Borra solo *.o
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Archivos .o eliminados."

fclean: clean
	@$(RM) $(NAME) .bonus
	@echo "Todo limpio."

re: fclean all

.PHONY: all clean fclean re bonus
