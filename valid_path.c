/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:11:51 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/16 09:51:39 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_map_check *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->collectibles = 0;
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
			map->collectibles++;
		y++;
	}
}

void	find_start(t_map_check *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
		{
			flood_fill(map, x, y);
			break ;
		}
		y++;
	}
}

void	flood_fill(t_map_check *map, int x, int y)
{
	char	*target;
	char	wall;

	wall = '1';
	target = "0CPE";
	if (map->map[x][y] == wall || map->map[x][y] == 'o')
		return ;
	if (!ft_strchr(target, map->map[x][y]))
		return ;
	if (map->map[x][y] == 'P' || map->map[x][y] == 'C' || map->map[x][y] == 'E')
		map->map[x][y] += 32;
	else
		map->map[x][y] = 'o';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	valid_path(t_map_check *map, t_comp *c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[x][y])
	{
		if (map->map[x][y] == 'e')
			c->e--;
		if (map->map[x][y] == 'c')
			c->c--;
		if (map->map[x][y] == 'p')
			c->p--;
		if (map->map[x][y + 1] == 0)
		{
			y = 0;
			x++;
			if (!map->map[x])
				break ;
		}
		y++;
	}
	if (c->p != 0 || c->e != 0 || c->c != 0)
		return (0);
	return (1);
}
