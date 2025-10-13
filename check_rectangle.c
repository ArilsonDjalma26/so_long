/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:31:43 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/04 16:31:49 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(char **map, t_game *game)
{
	int	width;
	int	i;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			print_error("O mapa nao e rectagulo\n", game);
		i++;
	}
	game->width = width;
	game->height = i;
}
