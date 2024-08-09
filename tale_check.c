/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tale_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:00:17 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/22 10:03:14 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_tale(t_map_check *map, t_mlx *mlx, int prev_x, int prev_y)
{
	if (map->map[mlx->sprite_y][mlx->sprite_x] == '1'
		|| (mlx->sprite_y == prev_x && mlx->sprite_x == prev_y))
		return (0);
	else if (map->map[mlx->sprite_y][mlx->sprite_x] == 'c')
	{
		map->collectibles--;
		map->map[prev_x][prev_y] = 'o';
	}
	else if (prev_x == mlx->ex_x && prev_y
		== mlx->ex_y && map->collectibles != 0)
		map->map[prev_x][prev_y] = 'e';
	else if (mlx->sprite_y == mlx->ex_x && mlx->sprite_x
		== mlx->ex_y && map->collectibles == 0)
	{
		map->map[mlx->sprite_y][mlx->sprite_x] = 'p';
		map->map[prev_x][prev_y] = 'o';
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
	draw_map(mlx, map);
	if ((mlx->sprite_y != prev_x || mlx->sprite_x != prev_y))
	{
		mlx->move++;
		ft_printf("Move: %i\n", mlx->move);
		end_game(mlx, map);
	}
}
