#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define TILE_SIZE 32

typedef struct s_img
{
    void    *player;
    void    *collect;
    void    *floor;
    void    *wall;
    void    *block1;
    void    *exit;
    void    *planet;
    void    *star;
} t_img;

typedef struct s_game
{
    void    *mlx;
    void    *mlx_win;
    t_img   img;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     player_count;
    int     collect_count;
    int     exit_count;
}   t_game;

int     count_line(int fd);
char    **read_map(char *file);
void    draw_map(t_game *game);
void    load_images(t_game *game);
void	exit_error(const char *msg);
void	free_map(char **map);
void	print_error(const char *msg, t_game *game);
void    parse_map(char *file, t_game *game);
void    check_rectangle(char **map, t_game *game);
void    init_game(t_game *game);
void    check_walls(char **map, t_game *game);
void    check_elements(char **map, t_game *game);
#endif
