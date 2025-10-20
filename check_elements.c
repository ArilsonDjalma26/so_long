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
	if (!ft_strchr("10PBEC", c))
		print_error("Mapa contem caracteres invalidos", game);
	if (c == 'P')
		game -> player_count++;
	else if (c == 'E')
		game -> exit_count++;
	else if (c == 'C')
		game -> collect_count++;
}

void	check_elements(char **map, t_game *game)
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
	if ((game->player_count != 1)
		|| (game -> collect_count < 1) || (game->exit_count != 1))
		print_error ("Mapa deve ter 1 (P) 1 (E) e ao menos 1 (C)", game);
}
