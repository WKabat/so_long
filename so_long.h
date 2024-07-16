/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:11:38 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/15 16:29:40 by wkabat           ###   ########.fr       */
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

typedef struct s_comp
{
	int		e;
	int		p;
	int		c;
	int		i;
	char	*com;
}				t_comp;

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
	char	*buff;
	char	**map;
	int		col;
	int		rows;
	int		collectibles;

}				t_map_check;

int		key_press(int keycode, void *param);
void	free_space(t_map_check *map);
int		is_rectangular(t_map_check *map);
int		read_map(char *filename, t_map_check *map, t_comp *c);
int		check_map(t_map_check *map, t_comp *c);
int		is_lines_equal(t_map_check *map);
void	set_lines(t_map_check	*map);
void	fill_buffer(int fd, t_map_check *map);
int		right_comp(t_map_check *map, t_comp *c);
int		is_closed(t_map_check *map);
void	count_collectibles(t_map_check *map);
void	find_start(t_map_check *map);
void	flood_fill(t_map_check *map, int x, int y);
int		valid_path(t_map_check *map, t_comp *c);

#endif