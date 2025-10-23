/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:38 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/23 16:54:21 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(const char *msg)
{
	write (2, "Error\n", 6);
	ft_putendl_fd (msg, 2);
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}

void	print_error(const char *msg, t_game *game)
{
	write (2, "Error\n", 6);
	ft_putendl_fd (msg, 2);
	write (2, "\n", 1);
	free_map(game->map);
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

void	free_images(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game -> img.collect)
		mlx_destroy_image(game -> mlx, game -> img.collect);
	if (game -> img.exit)
		mlx_destroy_image(game -> mlx, game -> img.exit);
	if (game -> img.floor)
		mlx_destroy_image(game -> mlx, game -> img.floor);
	if (game -> img.player)
		mlx_destroy_image(game -> mlx, game -> img.player);
	if (game -> img.wall)
		mlx_destroy_image(game -> mlx, game -> img.wall);
}

void	cleanup_and_exit(t_game *game, const char *msg)
{
	write (2, "Error\n", 6);
	if (msg)
		ft_putendl_fd (msg, 2);
	write(2, "\n", 1);
	free_images (game);
	if (game)
	{
		if (game -> map)
			free_map(game -> map);
		if (game -> mlx && game -> mlx_win)
			mlx_destroy_window(game -> mlx, game -> mlx_win);
		if (game -> mlx)
		{
			mlx_destroy_display (game -> mlx);
			free (game -> mlx);
		}	
	}
	exit (EXIT_FAILURE);
}
