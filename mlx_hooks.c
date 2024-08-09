/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:33:31 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/22 12:56:06 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		mlx_free(game->mlx);
		free_space(game->map);
		exit (0);
	}
	else if (keycode != 65307)
		sprite_move(keycode, game->map, game->mlx);
	return (0);
}

int	cross_clicked(t_game *game)
{
	mlx_free(game->mlx);
	free_space(game->map);
	exit(0);
}
