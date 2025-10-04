/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:54:05 by aalbano           #+#    #+#             */
/*   Updated: 2025/09/30 15:54:07 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while(game -> map[y])
    {
        x = 0;
        while(game -> map[y][x])
        {
            if (game -> map[y][x] == '1')
                mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game -> map[y][x] == '0')
                    mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.floor, x * TILE_SIZE, y * TILE_SIZE);
            else if (game -> map[y][x] == 'P')
                    mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.player, x * TILE_SIZE, y * TILE_SIZE);
            else if (game -> map[y][x] == 'C')
                    mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.collect, x * TILE_SIZE, y * TILE_SIZE);
            else if (game -> map[y][x] == 'E')
                    mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.exit, x * TILE_SIZE, y * TILE_SIZE);
            else if (game -> map[y][x] == 'p')
                    mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.planet, x * TILE_SIZE, y * TILE_SIZE);
            else if (game -> map[y][x] == 'B')
                    mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.block1, x * TILE_SIZE, y * TILE_SIZE);
            else if (game -> map[y][x] == 'S')
                    mlx_put_image_to_window(game -> mlx, game -> mlx_win, game -> img.star, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}