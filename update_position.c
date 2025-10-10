#include "so_long.h"

void    update_position(t_game *game, int new_x, int new_y)
{
    char    next;

    next = game->map[new_y][new_x];
    if (next == 'C')
        game->collect_count--;
    if (next == 'E' && game->collect_count == 0)
        handle_close(game);
    game->map[game->player_y][game->player_x] = '0';
    game->map[new_y][new_x] = 'P';
    game->player_y = new_y;
    game->player_x = new_x;
    game->moves++;
    ft_printf("Moves:%d\n", game->moves);
}