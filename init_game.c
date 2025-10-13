/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
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
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->img.exit = NULL;
	game->img.collect = NULL;
	game->img.player = NULL;
	game->img.floor = NULL;
	game->img.block1 = NULL;
	game->img.wall = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_count = 0;
	game->collect_count = 0;
	game->exit_count = 0;
	game->moves = 0;
	game -> reached_exit = 0;
	game -> collected = 0;
}
