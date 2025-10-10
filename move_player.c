#include "so_long.h"

void    move_player(t_game *game, int dx, int dy)
{
    int     new_x = game->player_x + dx;
    int     new_y = game->player_y + dy;
    char    next;

    next = game->map[new_y][new_x];
    if (next == '1' || next == 'B')
        return ;

    update_position(game, new_x, new_y);
    draw_map(game);
}