/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:11:38 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/09 12:06:04 by wkabat           ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		img_w;
	int		img_h;
	int		cat;
}				t_mlx;

typedef struct s_map_check
{
	char	*map_buffer;
	char	**map;
	int		col;
	int		rows;

}				t_map_check;

int		key_press(int keycode, void *param);
int		valid_size(t_map_check *map);
int	read_map(char *filename, t_map_check *map);
int		check_map(t_map_check *map);

#endif