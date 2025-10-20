/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:32:06 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/04 16:32:09 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((y == 0) || (y == game -> height - 1)
				|| (x == 0) || (x == game -> width - 1))
			{
				if (map[y][x] != '1')
					print_error ("Mapa nao esta rodeado de paredes", game);
			}
			x++;
		}
		y++;
	}
}
