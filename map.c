/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:48:23 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/10 16:20:17 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map_check *map)
{
	if ((!is_rectangular(map)) || (!is_lines_equal(map)) || (!right_comp(map)))
	{
		errno = 1;
		perror("Error\nMap is invalid!");
		return (0);
	}
	if (map->map != NULL)
	{
		if (!is_closed(map))
		{
			errno = EINVAL;
			perror("Error\nMap is invalid!");
			return (0);
		}
	}
	return (1);
}

void	set_lines(t_map_check	*map)
{
	int			i;

	i = 0;
	map -> rows = 0;
	while (map -> buff[i])
	{
		if (map -> buff[i] == '\n' || map -> buff[i + 1] == '\0')
			map -> rows++;
		i++;
	}
}

void	fill_buffer(int fd, t_map_check *map)
{
	char		*temp;
	char		*line;

	line = get_next_line(fd);
	while (line)
	{
		temp = map -> buff;
		map -> buff = ft_strjoin(temp, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
}

int	read_map(char *filename, t_map_check *map)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	fill_buffer(fd, map);
	set_lines(map);
	map -> map = ft_split(map -> buff, '\n');
	if (!check_map(map))
	{
		free_space(map);
		return (0);
	}
	return (1);
}

int	main(void)
{
	char		*buff;
	int			i;
	t_map_check	map;

	map.buff = NULL;
	map.map = NULL;
	map.col = 0;
	i = 0;
	buff = "map.ber";
	read_map(buff, &map);
	if (!map.map)
		return (0);
	while (i < map.rows)
	{
		printf("%s\n", map.map[i]);
		free(map.map[i]);
		i++;
	}
	free(map.map);
	free(map.buff);
	return (0);
}
