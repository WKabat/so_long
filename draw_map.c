/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:57:05 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/19 16:03:49 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_sprite_position(t_map_check *map, t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	mlx->sprite_x = 0;
	mlx->sprite_y = 0;
	y = 0;
	while (map->map[x] != NULL)
	{
		y = 0;
		while (map->map[x][y] != '\0')
		{
			if (map->map[x][y] == 'p')
			{
				mlx->sprite_y = x;
				mlx->sprite_x = y;
			}
			y++;
		}
		x++;
	}
}

void	window_size(t_mlx *mlx, t_map_check *map)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	len = 0;
	mlx->tile_size = 32;
	while (map->map[x] != NULL)
	{
		y = 0;
		if (map->map[0][y] != 0)
		{
			len++;
			y++;
		}
		while (map->map[x][y] != '\0')
			y++;
		x++;
	}
	mlx->screen_x = y * mlx->tile_size;
	mlx->screen_y = x * mlx->tile_size;
}

void	tiles(t_mlx *mlx, t_map_check *map, int x, int y)
{
	if (map->map[x][y] == '1')
		mlx->wall = mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->wall_img, y * mlx->tile_size, x * mlx->tile_size);
	else if (map->map[x][y] == 'p')
		mlx->sprite = mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->sprite_img, mlx->sprite_x * mlx->tile_size,
				mlx->sprite_y * mlx->tile_size);
	else if (map->map[x][y] == 'c')
		mlx->collect = mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->collect_img, y * mlx->tile_size,
				x * mlx->tile_size);
	else if (map->map[x][y] == 'o')
		mlx->back = mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->back_img, y * mlx->tile_size, x * mlx->tile_size);
	else if (map->map[x][y] == 'e')
	{
		mlx->exit = mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->exit_img, y * mlx->tile_size, x * mlx->tile_size);
		mlx->ex_x = x;
		mlx->ex_y = y;
	}
}

void	draw_map(t_mlx *mlx, t_map_check *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map[x] != NULL)
	{
		y = 0;
		while (map->map[x][y] != '\0')
		{
			if (map->map[x][y] == '1')
				tiles(mlx, map, x, y);
			else if (map->map[x][y] == 'p')
				tiles(mlx, map, x, y);
			else if (map->map[x][y] == 'c')
				tiles(mlx, map, x, y);
			else if (map->map[x][y] == 'o')
				tiles(mlx, map, x, y);
			else if (map->map[x][y] == 'e')
				tiles(mlx, map, x, y);
			y++;
		}
		x++;
	}
}
