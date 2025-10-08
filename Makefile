# Nome do executável
NAME = so_long

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Diretórios
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx
GNL_DIR = ./get_next_line
PRINTF_DIR = ./ft_printf

# Arquivos fonte
SRCS = so_long.c \
       init.c \
       draw.c \
       readmap.c \
	   errors.c \
	   parse_map.c \
	   check_rectangle.c \
	   check_walls.c \
	   check_elements.c \
	   init_game.c \
       $(GNL_DIR)/get_next_line.c \
       $(GNL_DIR)/get_next_line_utils.c \

# Objetos
OBJS = $(SRCS:.c=.o)

# Bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Flags extras para linkar no Linux (X11 e math)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Regra principal
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

# Compila libft
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)
# Compila mlx

# Limpar objetos
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
# make -C $(MLX_DIR) clean

# Limpar tudo
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Recompilar do zero
re: fclean all

.PHONY: all clean fclean re