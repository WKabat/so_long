/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:11:51 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/12 14:48:41 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles(t_map_check *map)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (map->map[x][y])
	{
		if (map->map[x][y + 1] == 0)
		{
			y = 0;
			x++;
			if (!map->map[x])
				break ;
		}
		if (map->map[x][y] == 'C')
			c++;
		y++;
	}
	return (c);
}

void	find_start(t_map_check *map)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = count_collectibles(map);
	while (map->map[x][y])
	{
		if (map->map[x][y + 1] == 0)
		{
			y = 0;
			x++;
			if (!map->map[x])
				break ;
		}
		if (map->map[x][y] == 'P')
			flood_fill(map, x, y, c);
		y++;
	}
}

void	flood_fill(t_map_check *map, int x, int y, int c)
{
	char	*target;
	char	wall;
	int		exit;

	wall = '1';
	exit = 0;
	target = "0CPE";
	if (map->map[x][y] == wall || map->map[x][y] == 'o')
		return ;
	if (!ft_strchr(target, map->map[x][y]))
		return ;
	if (map->map[x][y] == 'P' || map->map[x][y] == 'C' || map->map[x][y] == 'E')
	{
		if (map->map[x][y] == 'C')
			c--;
		if (map->map[x][y] == 'E')
			exit++;
		map->map[x][y] += 32;
	}
	else
		map->map[x][y] = 'o';
	flood_fill(map, x + 1, y, c);
	flood_fill(map, x - 1, y, c);
	flood_fill(map, x, y + 1, c);
	flood_fill(map, x, y - 1, c);
}
