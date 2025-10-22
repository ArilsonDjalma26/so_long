/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:34:05 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/17 12:41:01 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i <  height && map[i])
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
	if (x < 0 || x >= game->width || y < 0 || y >= game->height || map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
}

void check_reachable(char **map, t_game *game)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')			
			{
				free_map(map);
				print_error("Mapa deve ter caminhos validos!", game);
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_game *game)
{
	char	**temp_map;

	temp_map = copy_map(game -> map, game -> height);
	if (!temp_map)
		print_error("Erro ao copiar o mapa", game);
	flood_fill(temp_map, game -> player_x, game -> player_y, game);
	check_reachable(temp_map, game);
	free_map(temp_map);
}