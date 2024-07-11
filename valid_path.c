/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:11:51 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/11 16:42:13 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	 find_start_count_c(t_map_check *map)
{	
	t_path valid;

	valid.x = 0;
	valid.y = 0;
	valid.c = 0;
	while(map->map[valid.x][valid.y])
	{
		if(map->map[valid.x][valid.y] == 0)
		{
			valid.y = 0;
			valid.x++;
		}
		if(map->map[valid.x][valid.y] == 'P')
			flood_fill(valid.x, valid.y);

	}

}

void	flood_fill(int x, int y)
{

}