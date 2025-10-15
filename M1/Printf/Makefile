# --- Variables de configuración ---

# Nombre de la librería que vamos a crear
NAME = libftprintf.a

# Compilador y sus flags. -I. e -Ilibft le dicen al compilador que busque
# los archivos de cabecera (.h) en el directorio actual y en el directorio libft.
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I. -Ilibft


# Comandos comunes
AR = ar rcs
RM = rm -f
MAKE = make

# --- Archivos del proyecto ---

# Lista de todos los archivos fuente (.c) de tu proyecto
SRCS = ft_printf.c \
       utils_01.c \
       utils_02.c

# Genera automáticamente la lista de archivos objeto (.o) a partir de los .c
OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

# --- Variables de la sub-librería (libft) ---

# Directorio donde se encuentra la librería libft
LIBFT_DIR = libft
# Ruta completa al archivo de la librería libft.a
LIBFT_A = $(LIBFT_DIR)/libft.a

# --- Reglas de construcción ---

# Regla por defecto que se ejecuta con 'make'
all: $(NAME)

# Regla para crear la librería principal: libftprintf.a
# Depende de nuestros archivos objeto (.o) y de que la librería libft.a ya exista.
$(NAME): $(OBJS) $(LIBFT_A)
	# Archivamos SÓLO los archivos objeto de este proyecto en libftprintf.a
	@$(AR) $(NAME) $(OBJS)
	@echo "✅ libftprintf.a creada correctamente."

# Regla para construir la librería libft.a.
# Make detecta que $(NAME) depende de $(LIBFT_A), así que ejecutará
# esta regla primero. Entra en el directorio 'libft' y ejecuta su propio make.
$(LIBFT_A):
	@echo "Construyendo la librería dependiente: libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Regla genérica para compilar cualquier archivo .c en un .o
# $< es el primer prerrequisito (el .c) y $@ es el objetivo (el .o).
%.o: %.c $(HEADERS)
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# --- Reglas de limpieza ---

# 'make clean': Borra solo los archivos objeto de este proyecto y de libft
clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Archivos objeto (.o) eliminados."

# 'make fclean': Ejecuta 'clean' y además borra las librerías .a generadas
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️ Todo limpio."

# 'make re': Reconstruye todo el proyecto desde cero
re: fclean all

# --- Reglas Phony ---
# Declara reglas que no representan archivos para evitar conflictos.
.PHONY: all clean fclean re
