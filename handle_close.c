#include "so_long.h"


int handle_close(t_game *game)
{
    free_map(game->map);
    mlx_destroy_window(game->mlx, game->mlx_win);
    exit(0);
    return(0);
}