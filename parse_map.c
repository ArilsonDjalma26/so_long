/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:32:35 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/04 16:32:40 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *file, t_game *game)
{
	game -> map = read_map (file);
	if (!game->map)
		exit_error("Erro ao ler o mapa\n");
	check_rectangle (game->map, game);
	check_walls (game->map, game);
	check_elements (game->map, game);
	check_path(game);
}
