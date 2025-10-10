# include "so_long.h"

int     handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        handle_close(game);
    else if(keycode == KEY_W)
        move_player(game, 0, -1);
    else if(keycode == KEY_S)
        move_player(game, 0, 1);
    else if (keycode == KEY_A)
        move_player(game, -1, 0);
    else if (keycode == KEY_D)
        move_player(game, 1, 0);
    return (0);
}