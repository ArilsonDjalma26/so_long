/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:14:41 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/23 16:52:52 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game -> mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit(game, "Erro ao inicializar Minilibx!");
	load_images(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width
			* TILE_SIZE, game->height * TILE_SIZE, "so_long");
	if (!game->mlx_win)
		cleanup_and_exit(game, "Erro ao criar janela!");
	draw_map(game);
}
