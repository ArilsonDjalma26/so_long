/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:30:56 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/23 15:14:26 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_char(char c, t_game *game)
{
	if (!ft_strchr("10PEC", c))
		print_error("Caractere invalido no mapa!", game);
	if (c == 'P')
		game->player_count++;
	if (c == 'E')
		game->exit_count++;
	if (c == 'C')
		game->collect_count++;
}

static void	store_player_pos(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
}

void	check_elements(char **map, t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			validate_char(map[y][x], game);
			if (map[y][x] == 'P')
				store_player_pos(game, x, y);
		}
	}
	if (game->exit_count != 1)
		print_error("Mapa deve ter 1 porta!", game);
	if (game->player_count != 1)
		print_error("Mapa deve ter 1 player!", game);
	if (game->collect_count < 1)
		print_error("Mapa deve ter 1 coletavel!", game);
}
