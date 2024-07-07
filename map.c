/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:48:23 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/07 21:04:33 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "minilibft/minilibft.h"
#include <string.h>
#include <errno.h>

int	count_lines(char *str)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			line++;
		i++;
	}
	return (line);
}

char **set_lines(char *buffer)
{
	char	**map;
	int		lines;

}

char *fill_buffer(int fd)
{
	char	*temp;
	char	*buffer;
	char	*line;

	buffer = malloc(sizeof(char *));
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = buffer;
		buffer = ft_strjoin(temp, line);
		free(temp);
		free(line);
	}
	return (buffer);
}

char	**map(char *filename)
{
	int		fd;
	char	*buffer;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	buffer = fill_buffer(fd);

	return (map);
}

int	main()
{
	// char 	**map_result;
	char	*buffer;

	buffer = "map.ber";
	// map_result = map(buffor);
	// if (map_result != NULL && map_result[0] != NULL)
		printf("%s\n", map(buffer));
	return (0);
}