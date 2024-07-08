/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:02:36 by wkabat            #+#    #+#             */
/*   Updated: 2024/06/27 10:47:21 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		exit (0);
	return (0);
}

int	main(void)
{
	t_mlx		mlx;
	char		*param;

	param = NULL;
	mlx.path = "./xpm/cat.xpm";
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 600, "so_long");
	mlx.img = mlx_xpm_file_to_image(mlx.mlx, mlx.path, &mlx.img_w, &mlx.img_h);
	mlx.cat = mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 450, 300);
	mlx_key_hook(mlx.win, key_press, param);
	mlx_loop(mlx.mlx);
}
