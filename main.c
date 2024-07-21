/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:02:36 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/20 18:42:53 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_and_variables(t_mlx *mlx, t_game *game, t_map_check *map)
{
	mlx->move = 0;
	game->map = &map;
	game->mlx = &mlx;
	map->buff = NULL;
	map->map = NULL;
	map->col = 0;
	mlx->victory = 0;
	mlx->sprite_img_path = "./xpm/sprite.xpm";
	mlx->wall_img_path = "./xpm/wall.xpm";
	mlx->collect_img_path = "./xpm/coin.xpm";
	mlx->exit_img_path = "./xpm/exit.xpm";
	mlx->back_img_path = "./xpm/back.xpm";
}

void	img_and_win(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, mlx->screen_x,
			mlx->screen_y, "so_long");
	mlx->sprite_img = mlx_xpm_file_to_image(mlx->mlx, mlx->sprite_img_path,
			&mlx->sprite_img_w, &mlx->sprite_img_h);
	mlx->wall_img = mlx_xpm_file_to_image(mlx->mlx, mlx->wall_img_path,
			&mlx->wall_img_w, &mlx->wall_img_h);
	mlx->collect_img = mlx_xpm_file_to_image(mlx->mlx, mlx->collect_img_path,
			&mlx->collect_img_w, &mlx->collect_img_h);
	mlx->back_img = mlx_xpm_file_to_image(mlx->mlx, mlx->back_img_path,
			&mlx->back_img_w, &mlx->back_img_h);
	mlx->collect_img = mlx_xpm_file_to_image(mlx->mlx, mlx->collect_img_path,
			&mlx->collect_img_w, &mlx->collect_img_h);
	mlx->exit_img = mlx_xpm_file_to_image(mlx->mlx, mlx->exit_img_path,
			&mlx->exit_img_w, &mlx->exit_img_h);
}

int	main(void)
{
	t_mlx		mlx;
	t_map_check	map;
	t_comp		c;
	t_game		game;

	path_and_variables(&mlx, &game, &map);
	mlx.mlx = mlx_init();
	read_map("./maps/small_map.ber", &map, &c);
	count_collectibles(&map);
	window_size(&mlx, &map);
	img_and_win(&mlx);
	get_sprite_position(&map, &mlx);
	draw_map(&mlx, &map);
	mlx_key_hook (mlx.win, key_press, &game);
	mlx_hook (mlx.win, 17, 1l<<17,cross_clicked, &mlx);
	mlx_loop (mlx.mlx);
	// free_space(&map);
}
