/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:58:21 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/11 15:58:22 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_game *game)
{
	free_map (game->map);
	mlx_destroy_window (game->mlx, game->mlx_win);
	exit (0);
	return (0);
}
