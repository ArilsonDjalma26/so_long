/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:26:36 by aalbano           #+#    #+#             */
/*   Updated: 2025/09/30 15:26:40 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void   *load_image(t_game *game, char *path, void **to_free[], int n)
{
        int     w;
        int     h;
        void    *img;

        img = mlx_xpm_file_to_image(game -> mlx, path, &w, &h);
        if (!img)
        {
                while(n--)
                        if(to_free[n])
                                mlx_destroy_image(game -> mlx, to_free[n]);
                mlx_destroy_window(game -> mlx, game -> mlx_win);
                mlx_destroy_display(game -> mlx);
                print_error(strerror(errno), game);
        }
        return (img);
}  

void	load_images(t_game *game)
{
     void       **img[6];
     char       *paths[6];
     int        i;

     i = 0;
     img[0] = &game -> img.block1;
     img[1] = &game -> img.collect;
     img[2] = &game -> img.exit;
     img[3] = &game -> img.floor;
     img[4] = &game -> img.player;
     img[5] = &game -> img.wall;
     paths[0] = "textures/block1.xpm";
     paths[1] = "textures/collect.xpm";
     paths[2] = "textures/exit.xpm";
     paths[3] = "textures/floor.xpm";
     paths[4] = "textures/player.xpm";
     paths[5] = "textures/wall.xpm";

     while(i < 6)
     {
        *img[i] = load_image(game, paths[i], img, i);
        i++;
     }
}
