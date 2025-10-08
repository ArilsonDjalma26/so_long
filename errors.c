/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:38 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/06 14:37:22 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(const char *msg)
{
	ft_printf("Erro\n%s", msg);
	exit(EXIT_FAILURE);
}

void	print_error(const char *msg, t_game *game)
{
	if(game)
		free_map(game->map);
	ft_printf("Erro\n%s", msg);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	if(!map)
		return ;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}