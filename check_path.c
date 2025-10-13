/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:34:05 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/13 13:37:41 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		game -> reached_exit = 1;
	if (map[y][x] == 'C')
		game -> collected++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

void	check_path(t_game *game)
{
	char	**temp_map;

	temp_map = copy_map(game -> map, game -> height);
	if (!temp_map)
		print_error("Erro ao copiar o mapa\n", game);
	flood_fill(temp_map, game -> player_x, game -> player_y, game);
	free_map (temp_map);
	if (game -> collected != game -> collect_count || !game -> reached_exit)
		print_error("Mapa impossivel de completar!\n", game);
}
