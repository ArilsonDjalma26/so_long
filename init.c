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

void    load_images(t_game *game)
{
    int     w;
    int     h;

    game->img.wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &w, &h);
    game->img.block1 = mlx_xpm_file_to_image(game->mlx, "sprites/block1.xpm", &w, &h);
    game->img.floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &w, &h);
    game->img.player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &w, &h);
    game->img.collect = mlx_xpm_file_to_image(game->mlx, "sprites/collect.xpm", &w, &h);
    game->img.exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &w, &h);
    game->img.planet = mlx_xpm_file_to_image(game->mlx, "sprites/planet.xpm", &w, &h);
}