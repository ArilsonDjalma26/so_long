/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:38 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/17 11:47:37 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(const char *msg)
{
	write (2, "Error\n", 5);
	ft_putendl_fd (msg, 2);
	exit (EXIT_FAILURE);
}

void	print_error(const char *msg, t_game *game)
{
	write (2, "Error\n", 5);
	ft_putendl_fd (msg, 2);
	if (game)
	{
		free_map(game->map);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	exit (EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}
