/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:30:56 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/17 12:38:56 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_tile(char c, t_game *game)
{
	if (!ft_strchr("10PEC", c))
		print_error("Mapa contem caracteres invalidos", game);
	if (c == 'P')
		game -> player_count++;
	else if (c == 'E')
		game -> exit_count++;
	else if (c == 'C')
		game -> collect_count++;
}

static void	check_element (t_game *game)
{
	int	coins;
	int players;
	int	doors;
	int x;
	int	y;

	coins = 0;
	players = 0;
	doors = 0;
	x = 0;
	y = 0;

	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				coins++;
			if (game->map[y][x] == 'P')
				players++;
			if (game->map[y][x] == 'E')
				doors++;
			x++;
		}
		y++;
	}

	if (doors != 1)
		print_error("Mapa deve ter 1 porta!", game);
	if (players != 1)
		print_error("Mapa deve ter 1 player!", game);
	if (coins < 1)
		print_error("Mapa deve ter pelo menos 1 coletavel!", game);
}
void	check_elements (char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			check_tile(map[y][x], game);
			if (map[y][x] == 'P')
			{
				game -> player_x = x;
				game -> player_y = y;
			}
			x++;
		}
		y++;
	}
	check_element(game);
}

