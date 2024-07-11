/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:11:38 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/11 16:41:37 by wkabat           ###   ########.fr       */
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

typedef struct s_com
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

}				t_map_check;

typedef struct s_path
{
	char	**start;
	int		c;
	int	x;
	int	y;
	int	c;
}				t_path;


int		key_press(int keycode, void *param);
void	free_space(t_map_check *map);
int		is_rectangular(t_map_check *map);
int		read_map(char *filename, t_map_check *map);
int		check_map(t_map_check *map);
int		is_lines_equal(t_map_check *map);
void	set_lines(t_map_check	*map);
void	fill_buffer(int fd, t_map_check *map);
int		right_comp(t_map_check *map);
int		is_closed(t_map_check *map);

#endif