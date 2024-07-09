/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:11 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/09 14:57:42 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_map_check *map)
{
	int	i;

	i = 0;
	map -> col = 0;
	while (map -> buff[i] != '\n')
	{
		i++;
		map -> col++;
	}
	if (map -> rows == map -> col)
		return (0);
	return (1);
}

int	is_lines_equal(t_map_check *map)
{
	int	length;
	int	i;

	i = 0;
	length = 0;
	while (map -> buff[i] != 0)
	{
		if (map -> buff[i] == '\n')
		{
			if (length != map -> col)
				return (0);
			length = 0;
			i++;
		}
		length++;
		i++;
	}
	return (1);
}

int	right_components(t_map_check *map)
{
	t_comp	c;

	c.i = 0;
	c.c = 0;
	c.e = 0;
	c.p = 0;
	c.com = "01CPE";
	while (map -> buff[c.i] != 0)
	{
		if (ft_strchr(c.com, map->buff[c.i]) || map->buff[c.i] == '\n')
		{
			if (map -> buff[c.i] == 'E')
				c.e++;
			else if (map -> buff[c.i] == 'P')
				c.p++;
			else if (map -> buff[c.i] == 'C')
				c.c++;
		}
		else if ((!ft_strchr(c.com, map->buff[c.i]) || map->buff[c.i] != '\n'))
			return (0);
		c.i++;
	}
	if (c.c < 1 || c.e != 1 || c.p != 1)
		return (0);
	return (1);
}

// int	is_closed(t_map_check *map)
// {
	
// }
