/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:26:36 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/23 16:31:00 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_one(t_game *game, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(game -> mlx, path, &w, &h);
	if (!img)
		cleanup_and_exit (game, "Erro ao carregar textura!");
	return (img);
}

void	load_images(t_game *game)
{
	game -> img.collect = load_one (game, "textures/collect.xpm");
	game -> img.exit = load_one (game, "textures/exit.xpm");
	game -> img.floor = load_one (game, "textures/floor.xpm");
	game -> img.player = load_one (game, "textures/player.xpm");
	game -> img.wall = load_one (game, "textures/wall.xpm");
}
