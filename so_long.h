/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:11:38 by wkabat            #+#    #+#             */
/*   Updated: 2024/06/27 10:47:32 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

int	key_press(int keycode, void *param);

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
#endif