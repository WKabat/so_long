/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:22:03 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/16 18:13:23 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_space(t_map_check *map)
{
	int	i;

	i = 0;
	if (map->buff != NULL)
	{
		free (map -> buff);
		map -> buff = NULL;
	}
	if (map->map != NULL)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
		map -> map = NULL;
	}
}

// void	get_sprite_position(t_map_check *map, t_mlx *mlx)
// {
// 	int	x;
// 	int	y;

// 	while (map->map[x][y])
// 	{
// 		if (map->map[x][y] == 'p')
// 		{
// 			mlx->sprite_x = x;
// 			mlx->sprite_y = y;
// 		}
// 		if (map->map[x][y + 1] == 0)
// 		{
// 			y = 0;
// 			x++;
// 			if (!map->map[x])
// 				break ;
// 		}
// 		y++;
// 	}
// }
void	window_size(t_mlx *mlx, t_map_check *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	// mlx->tile_size = 32;
	while (map->map[x][y])
	{
		mlx->screen_x = x * mlx->tile_size;
		mlx->screen_y = y * mlx->tile_size;
		if (map->map[x][y + 1] == 0)
		{
			y = 0;
			x++;
			if (!map->map[x])
				break ;
		}
		y++;
	}
}

void	draw_map(t_mlx *mlx, t_map_check *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[x][y])
	{
		if (map->map[x][y] == 0)
		{
			y = 0;
			x++;
			if (!map->map[x])
				break ;
		}
		if (map->map[x][y] == '1')
			mlx->wall = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall_img, x * mlx->tile_size, y * mlx->tile_size);
		else if (map->map[x][y] == 'p')
			mlx->sprite = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprite_img, x * mlx->tile_size, y * mlx->tile_size);
		else if (map->map[x][y] == 'c')
			mlx->collect = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collect_img, x * mlx->tile_size, y * mlx->tile_size);
		else if (map->map[x][y] == 'o')
			mlx->back = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->back_img, x * mlx->tile_size, y * mlx->tile_size);
		else if (map->map[x][y] == 'e')
			mlx->exit = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit_img, x * mlx->tile_size, y * mlx->tile_size);
		y++;
	}
}
// void	clear_sprite(t_mlx *mlx)
// {
// 	void *img;
// 	char *data;

// 	img = mlx_new_image(mlx->mlx, 
// }

// int	key_press(int keycode, t_mlx *mlx)
// {
// 	if (keycode == 65307)
// 		exit (0);
// 	// if (keycode == 65361)
// 	// 	mlx->sprite_x -= 10;
// 	// if (keycode == 65362)
// 	// 	mlx->sprite_y -= 10;
// 	// if (keycode == 65363)
// 	// 	mlx->sprite_x += 10;
// 	// if (keycode == 65364)
// 	// 	mlx->sprite_y += 10;
// 	// clear_sprite(mlx);

// // 	mlx_put_image_to_window(mlx->mlx,mlx->win,mlx->img, mlx->sprite_x, mlx->sprite_y);
// // 	return (0);
// }

int	cross_clicked(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}