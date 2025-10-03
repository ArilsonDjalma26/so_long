/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:14:40 by aalbano           #+#    #+#             */
/*   Updated: 2025/09/25 12:05:01 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     count_map_height(char **map)
{
    int     y;

    y = 0;
    while(map[y])
		y++;
    return (y);
}

int main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
	return (1);

	game.map = read_map("maps/map.ber");
	if (!game.map)
		return (1);
	game.height = count_map_height(game.map);
	game.width = ft_strlen(game.map[0]);
	game.mlx_win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");

	load_images(&game);
	draw_map(&game);

	mlx_loop(game.mlx);
}