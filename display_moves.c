/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:57:53 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/13 13:41:06 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*str;
	char	*num;

	num = ft_itoa(game->moves);
	str = ft_strjoin("Movimentos: ", num);
	mlx_string_put(game->mlx, game->mlx_win, 40, 50, 0xFFFFFF, str);
	free(str);
	free(num);
}
