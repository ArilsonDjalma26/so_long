/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:14:40 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/17 11:45:42 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		exit_error("Uso: ./so_long <maps/map.ber>");
	check_extension(argv[1], ".ber");
	parse_map(argv[1], &game);
	init_game(&game, argv[1]);
	mlx_hook(game.mlx_win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.mlx_win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
}