/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:30:56 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/04 16:31:00 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_elements(char **map, t_game *game)
{
    int     x;
    int     y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (!ft_strchr("10PBECSp", map[y][x]))
                print_error("Mapa contem caracteres invalidos\n", game);
        
            if (map[y][x] == 'P')
            {
                game->player_count++;
                game->player_x = x;
                game->player_y = y;
            }
            if (map[y][x] == 'E')
                game->exit_count++;
            if (map[y][x] == 'C')
                game->collect_count++;
            x++;
        }
        y++;
    }
    if ((game->player_count != 1) || (game->collect_count < 1) || (game->exit_count != 1))
        print_error("Mapa de ter um P um E e ao menos um C\n", game);
}