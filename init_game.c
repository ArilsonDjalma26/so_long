/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:14:41 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/08 10:15:16 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->moves = 0;
	if (!game->mlx)
		print_error("Erro ao inicializar Minilibx", game);
	load_images(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long");
	if (!game->mlx_win)
		print_error("Erro ao criar janela\n", game);
	draw_map(game);//Verificar erro
}
