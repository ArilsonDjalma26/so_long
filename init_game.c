/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:14:41 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/28 18:21:13 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int		screen_x;
	int		screen_y;

	game -> mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit(game, "Erro ao inicializar Minilibx!");
	load_images(game);
	mlx_get_screen_size(game -> mlx, &screen_x, &screen_y);
	if (game -> width * TILE_SIZE > screen_x
		|| game ->height * TILE_SIZE > screen_y)
		cleanup_and_exit(game, "Mapa maior do que tamanho da tela!");
	game->mlx_win = mlx_new_window(game->mlx, game -> width
			*TILE_SIZE, game ->height * TILE_SIZE, "so_long");
	ft_printf("%dx%d\n", game -> width, game -> height);
	if (!game->mlx_win)
		cleanup_and_exit(game, "Erro ao criar janela!");
	draw_map(game);
}
