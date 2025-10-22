/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:54:05 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/13 14:01:44 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game -> mlx,
		game -> mlx_win,
		img,
		x * TILE_SIZE,
		y * TILE_SIZE);
}

static void	draw_tile(t_game *game, int x, int y)
{
	char	c;

	c = game -> map[y][x];
	if (c == '1')
		put_img (game, game -> img.wall, x, y);
	else if (c == '0')
		put_img (game, game -> img.floor, x, y);
	else if (c == 'P')
		put_img (game, game -> img.player, x, y);
	else if (c == 'C')
		put_img (game, game -> img.collect, x, y);
	else if (c == 'E')
		put_img (game, game -> img.exit, x, y);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game -> map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			draw_tile (game, x, y);
			x++;
		}
		y++;
	}
}
