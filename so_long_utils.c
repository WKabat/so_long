/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:22:03 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/17 20:13:05 by wkabat           ###   ########.fr       */
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
	int len;

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
				mlx->wall = mlx_put_image_to_window(mlx->mlx, mlx->win,
						mlx->wall_img, y * mlx->tile_size, x * mlx->tile_size);
			else if (map->map[x][y] == 'p')
				mlx->sprite = mlx_put_image_to_window(mlx->mlx, mlx->win,
						mlx->sprite_img, mlx->sprite_x * mlx->tile_size,
						mlx->sprite_y * mlx->tile_size);
			else if (map->map[x][y] == 'c')
				mlx->collect = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collect_img, y * mlx->tile_size, x * mlx->tile_size);
			else if (map->map[x][y] == 'o')
				mlx->back = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->back_img, y * mlx->tile_size, x * mlx->tile_size);
			else if (map->map[x][y] == 'e')
			{
				mlx->exit = mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit_img, y * mlx->tile_size, x * mlx->tile_size);
				mlx->ex_x = x;
				mlx->ex_y = y;
			}
			y++;
		}
		x++;
	}	
}

void	check_keycode(int keycode, t_mlx *mlx)
{
	if (keycode == 65361 || keycode == 65362 || keycode == 65363 || keycode == 65364)
	{
		if (keycode == 65361)
			mlx->sprite_x--;
		else if (keycode == 65362)
			mlx->sprite_y--;
		else if (keycode == 65363)
			mlx->sprite_x++;
		else if (keycode == 65364)
			mlx->sprite_y++;
	}
}
void	end_game(t_mlx *mlx)
{
		mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0x00FF00, "Victory!");
   		// sleep(2);
    	// mlx_loop_end(mlx->mlx);
}

int	check_tale(t_map_check *map, t_mlx *mlx,int prev_x,int prev_y)
{	
	if (map->map[mlx->sprite_y][mlx->sprite_x] == '1' || (mlx->sprite_y == prev_x && mlx->sprite_x == prev_y))
			return (0);
	else if (map->map[mlx->sprite_y][mlx->sprite_x] == 'c')
	{
		map->collectibles--;
		map->map[prev_x][prev_y] = 'o';
	}
	else if (prev_x == mlx->ex_x && prev_y == mlx->ex_y && map->collectibles != 0)
		map->map[prev_x][prev_y] = 'e';
	else if (map->map[mlx->sprite_y][mlx->sprite_x] == 'e'  && map->collectibles == 0)
	{
		map->map[mlx->sprite_y][mlx->sprite_x] = 'p';
		map->map[prev_x][prev_y] = 'o';
		end_game(mlx);
	}
	else
		map->map[prev_x][prev_y] = 'o';
	map->map[mlx->sprite_y][mlx->sprite_x] = 'p';
	return (1);
}

void	sprite_move(int keycode, t_map_check *map, t_mlx *mlx)
{	
	int	prev_x;
	int	prev_y;

	prev_x = mlx->sprite_y;
	prev_y = mlx->sprite_x;
	check_keycode(keycode, mlx);
	if (!check_tale(map, mlx, prev_x, prev_y))
	{
		mlx->sprite_y = prev_x;
		mlx->sprite_x = prev_y;
	}
	if (mlx->sprite_y != prev_x || mlx->sprite_x != prev_y)
	{
		mlx->move++;
		ft_printf("Move: %i\n", mlx->move);
	}
	draw_map(mlx, map);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit (0);
	else
		sprite_move(keycode, game->map, game->mlx);
	return (0);
}

int	cross_clicked(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}