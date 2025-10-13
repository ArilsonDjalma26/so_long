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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error("Uso: ./so_long <maps/map.ber>\n");
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		exit_error("Mapa deve ter a extencao .ber\n");
	init_game(&game);
	parse_map(argv[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit_error("Erro ao inicializar Minilibx");
	game.mlx_win = mlx_new_window(game.mlx, game.width * TILE_SIZE,
			game.height * TILE_SIZE, "so_long");
	if (!game.mlx_win)
		exit_error("Erro ao criar janela\n");
	load_images(&game);
	draw_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.mlx_win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
}
