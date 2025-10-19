NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
MLX_DIR = ./minilibx
GNL_DIR = ./get_next_line
PRINTF_DIR = ./ft_printf
SRCS = so_long.c \
       init.c \
       draw.c \
       readmap.c \
	   errors.c \
	   parse_map.c \
	   check_rectangle.c \
	   check_walls.c \
	   check_path.c \
	   check_elements.c \
	   init_game.c \
	   update_position.c \
	   handle_keypress.c \
	   handle_close.c \
	   move_player.c \
	   display_moves.c \
       $(GNL_DIR)/get_next_line.c \
       $(GNL_DIR)/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
