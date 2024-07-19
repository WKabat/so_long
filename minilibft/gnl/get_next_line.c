/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:32:22 by wkabat            #+#    #+#             */
/*   Updated: 2024/06/03 12:23:45 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cleaner(char *line);
static char	*fill_line(int fd, char *bookmark, char *book);

char	*get_next_line(int fd)
{
	static char	*letters;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (letters);
		letters = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, letters, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	letters = cleaner(line);
	return (line);
}

static char	*fill_line(int fd, char *letters, char *buffer)
{
	ssize_t	read_text;
	char	*holder;

	read_text = 1;
	while (read_text > 0)
	{
		read_text = read(fd, buffer, BUFFER_SIZE);
		if (read_text == -1)
		{
			free (letters);
			return (NULL);
		}
		else if (read_text == 0)
			break ;
		buffer[read_text] = '\0';
		holder = letters;
		letters = ft_strjoin(holder, buffer);
		free(holder);
		holder = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (letters);
}

static char	*cleaner(char *line)
{
	char	*cutter;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	cutter = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*cutter == '\0')
	{
		free (cutter);
		cutter = NULL;
	}
	line[i + 1] = '\0';
	return (cutter);
}
//* main for file

/*int main()
{
	int	fd;
	char *line;

	fd = open("text.txt", O_RDONLY);

	if (fd == -1)
		printf("There is an error!");

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free (line);
	}
	free (line);
	return (0);
}*/

//* main for stdin

/* int main()
{
	char *line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}*/