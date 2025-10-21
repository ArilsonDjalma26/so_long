/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:58:08 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/11 15:58:10 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game -> player_x + dx;
	new_y = game -> player_y + dy;
	next = game->map[new_y][new_x];
	if ((next == '1') || (next == 'B')
		|| (next == 'E' && game->collect_count != 0))
		return ;
	update_position (game, new_x, new_y);
	draw_map (game);
	display_moves (game);
}
