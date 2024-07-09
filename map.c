/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:48:23 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/09 12:13:35 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_lines(t_map_check	*map)
{
	int			i;

	i = 0;
	map -> rows = 0;
	while (map -> map_buffer[i])
	{
		if (map -> map_buffer[i] == '\n' || map -> map_buffer[i + 1] == '\0')
			map -> rows++;
		i++;
	}
	map -> map = ft_split(map -> map_buffer, '\n');
}

void	fill_buffer(int fd, t_map_check *map)
{
	char		*temp;
	char		*line;

	line = get_next_line(fd);
	while (line)
	{
		temp = map -> map_buffer;
		map -> map_buffer = ft_strjoin(temp, line);
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
	if (!check_map(map))
	{
		perror("Error\nMap is invalid!");
		free (map -> map);
		free (map -> map_buffer);
		map -> map = NULL;
		map -> map_buffer = NULL;
		return (0);
	}
	return (1);
}

int	main(void)
{
	char		*buffer;
	int			i;
	t_map_check	map;

	map.map_buffer = NULL;
	map.map = NULL;
	map.col = 0;
	i = 0;
	buffer = "map.ber";
	read_map(buffer, &map);
	if (!map.map)
		return (0);
	while (i < map.rows)
	{
		printf("%s\n", map.map[i]);
		free(map.map[i]);
		i++;
	}
	free(map.map);
	free(map.map_buffer);
	return (0);
}
