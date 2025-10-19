/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:26:36 by aalbano           #+#    #+#             */
/*   Updated: 2025/09/30 15:26:40 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int		w;
	int		h;
	void	*mlx;

	game->xpm.file_w = "sprites/wall.xpm";
	game->xpm.file_b = "sprites/block1.xpm";
	game->xpm.file_f = "sprites/floor.xpm";
	game->xpm.file_p = "sprites/player.xpm";
	game->xpm.file_c = "sprites/collect.xpm";
	game->xpm.file_e = "sprites/exit.xpm";
        mlx = game -> mlx;
        game->img.wall = mlx_xpm_file_to_image (mlx, game->xpm.file_w, &w, &h);
        if (!game->img.wall)
                print_error("Erro ao carregar o sprite\n", game);
        game->img.block1 = mlx_xpm_file_to_image (mlx, game->xpm.file_b, &w, &h);
        if (!game->img.block1)
                print_error("Erro ao carregar o sprite\n", game);
        game->img.floor = mlx_xpm_file_to_image (mlx, game->xpm.file_f, &w, &h);
        if (!game->img.floor)
                print_error("Erro ao carregar o sprite\n", game);
        game->img.player = mlx_xpm_file_to_image (mlx, game->xpm.file_p, &w, &h);
        if (!game->img.player)
                print_error("Erro ao carregar o sprite\n", game);
        game->img.collect = mlx_xpm_file_to_image (mlx, game->xpm.file_c, &w, &h);
        if (!game->img.collect)
                print_error("Erro ao carregar o sprite\n", game);
        game->img.exit = mlx_xpm_file_to_image (mlx, game->xpm.file_e, &w, &h);
        if (!game->img.exit)
                print_error("Erro ao carregar o sprite\n", game);
}
