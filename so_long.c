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

int main(int argc, char **argv)
{
	(void)argc;
	if(!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		perror("Mapa deve ter a extencao .ber");
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
	return (1);

	game.map = read_map(argv[1]);
	
	if (!game.map)
		return (1);
	game.mlx_win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");

	load_images(&game);
	draw_map(&game);

	mlx_loop(game.mlx);
}