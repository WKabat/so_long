/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:11:38 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/19 15:59:26 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stddef.h>
# include "minilibx/mlx.h"
# include "minilibft/minilibft.h"
# include <X11/keysymdef.h>

typedef struct s_comp
{
	int		e;
	int		p;
	int		c;
	int		i;
	char	*com;
}				t_comp;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*sprite_img_path;
	char	*wall_img_path;
	char	*back_img_path;
	char	*collect_img_path;
	char	*exit_img_path;
	char	*sprite_img;
	char	*wall_img;
	char	*back_img;
	char	*collect_img;
	char	*exit_img;
	int		sprite_img_w;
	int		sprite_img_h;
	int		wall_img_w;
	int		wall_img_h;
	int		collect_img_w;
	int		collect_img_h;
	int		back_img_w;
	int		back_img_h;
	int		exit_img_w;
	int		exit_img_h;	
	int		map_width;
	int		map_height;
	int		screen_x;
	int		screen_y;
	int		sprite;
	int		wall;
	int		back;
	int		exit;
	int		collect;
	int		sprite_x;
	int		sprite_y;
	int		tile_size;
	int		move;
	int		ex_x;
	int		ex_y;
	int		victory;
}				t_mlx;

typedef struct s_map_check
{
	char	*buff;
	char	**map;
	int		col;
	int		rows;
	int		collectibles;

}				t_map_check;

typedef struct s_game
{
	t_map_check	*map;
	t_mlx		*mlx;
}				t_game;

int		key_press(int keycode, t_game *game);
void	free_space(t_map_check *map);
int		is_rectangular(t_map_check *map);
int		read_map(char *filename, t_map_check *map, t_comp *c);
int		check_map(t_map_check *map, t_comp *c);
int		is_lines_equal(t_map_check *map);
void	set_lines(t_map_check	*map);
void	fill_buffer(int fd, t_map_check *map);
int		right_comp(t_map_check *map, t_comp *c);
int		is_closed(t_map_check *map);
void	count_collectibles(t_map_check *map);
void	find_start(t_map_check *map);
void	flood_fill(t_map_check *map, int x, int y);
int		valid_path(t_map_check *map, t_comp *c);
int		cross_clicked(t_mlx *mlx);
void	window_size(t_mlx *mlx, t_map_check *map);
void	draw_map(t_mlx *mlx, t_map_check *map);
void	get_sprite_position(t_map_check *map, t_mlx *mlx);
void	sprite_move(int keycode, t_map_check *map, t_mlx *mlx);
int		check_tale(t_map_check *map, t_mlx *mlx, int prev_x, int prev_y);
void	check_keycode(int keycode, t_mlx *mlx);
void	tiles(t_mlx *mlx, t_map_check *map, int x, int y);
void	end_game(t_mlx *mlx, t_map_check *map);

#endif