# Nombre del ejecutable final
NAME = push_swap_game

# Compilador y Banderas (Flags)
CC = cc
# -g para debugging, -O2 para optimizar (puedes quitar -g al final)
CFLAGS = -Wall -Wextra -Werror -g

# Comando para borrar
RM = rm -f

# --- Archivos del Proyecto ---

# Lista de todos tus archivos .c
SRCS = 	node_creator.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		player_push_swap.c

# Lista de tus archivos .h (para dependencias)
HDRS = push_swap.h

# Lista de archivos objeto (.o) generada a partir de los .c
OBJS = $(SRCS:.c=.o)

# --- Reglas de Make ---

# Regla por defecto: compila todo
all: $(NAME)

# Regla para crear el ejecutable final (linkado)
# Depende de todos los archivos objeto (.o)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Juego Push Swap '($@)' compilado con éxito."

# Regla para compilar archivos .c en .o
# Depende de los .c y los .h (si un .h cambia, recompila)
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla 'clean': borra solo los archivos objeto
clean:
	$(RM) $(OBJS)
	@echo "Archivos objeto (.o) eliminados."

# Regla 'fclean': borra todo (objetos y ejecutable)
fclean: clean
	$(RM) $(NAME)
	@echo "Ejecutable y objetos eliminados."

# Regla 're': borra todo y vuelve a compilar
re: fclean all

# Declara las reglas que no crean archivos (para evitar conflictos)
.PHONY: all clean fclean re