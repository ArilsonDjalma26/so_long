/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:45:53 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/13 11:48:56 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define TILE_SIZE 32
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct t_xpm
{
	void	*file_w;
	void	*file_f;
	void	*file_p;
	void	*file_c;
	void	*file_e;
}t_file;

typedef struct s_img
{
	void	*player;
	void	*collect;
	void	*floor;
	void	*wall;
	void	*exit;
}t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_file	xpm;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_count;
	int		collect_count;
	int		exit_count;
	int		moves;
	int		collected;
	int		reached_exit;
} t_game;

int		count_line(int fd);
void	draw_map(t_game *game);
void	load_images(t_game *game);
void	exit_error(const char *msg);
void	free_map(char **map);
void	print_error(const char *msg, t_game *game);
void	parse_map(char *file, t_game *game);
void	check_rectangle(char **map, t_game *game);
void	init_game(t_game *game);
void	check_walls(char **map, t_game *game);
void	check_path(t_game *game);
void	check_elements(char **map, t_game *game);
void	check_extension(const char *filename, const char *ext);
void	update_position(t_game *game, int new_x, int new_y);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	display_moves(t_game *game);
char    **get_map(char *filename);
#endif
