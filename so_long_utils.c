/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:22:03 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/19 16:02:44 by wkabat           ###   ########.fr       */
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

void	check_keycode(int keycode, t_mlx *mlx)
{
	if (keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
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

void	end_game(t_mlx *mlx, t_map_check *map)
{
	if (mlx->sprite_y == mlx->ex_x && mlx->sprite_x
		== mlx->ex_y && map->collectibles == 0)
	{
		ft_printf("Victory!\n");
		mlx_loop_end(mlx->mlx);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit (0);
	else if (keycode != 65307)
		sprite_move(keycode, game->map, game->mlx);
	return (0);
}

int	cross_clicked(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
