/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:22:03 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/22 12:46:20 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_space(t_map_check *map)
{
	int	i;

	if (map != NULL)
	{
		i = 0;
		if (map->buff != NULL)
		{
			free (map -> buff);
			map -> buff = NULL;
		}
		if (map->map != NULL)
		{
			while (map->map[i] != NULL)
				free(map->map[i++]);
			free(map->map);
			map -> map = NULL;
		}
	}
}

void	prepare_game(t_mlx *mlx, t_map_check *map)
{
	mlx->mlx = mlx_init();
	count_collectibles(map);
	window_size(mlx, map);
	img_and_win(mlx);
	get_sprite_position(map, mlx);
	draw_map(mlx, map);
}
