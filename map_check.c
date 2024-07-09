/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:54:11 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/09 11:56:12 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_lines_equal(t_map_check *map);
int	valid_size(t_map_check *map);

int	check_map(t_map_check *map)
{
	if (!valid_size(map))
		return (0);
	if (!is_lines_equal(map))
		return (0);
	return (1);
}

int	valid_size(t_map_check *map)
{
	int	i;

	i = 0;
	map -> col = 0;
	while(map -> map_buffer[i] != '\n')
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
	while (map -> map_buffer[i] != 0)
	{
		if (map -> map_buffer[i] == '\n')
		{
			// printf("length: %i\n", length);
			// printf("rows: %i\n", map -> col);
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
