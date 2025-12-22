/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:00:16 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/17 11:00:18 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static size_t	close_fd(int fd, char *line)
{
	if (line)
		free(line);
	close(fd);
	return (1);
}

size_t	parse_map(const char *map_path)
{
	int		fd;
	char	*line;
	size_t	length;
	size_t	width;
	size_t	i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (close_fd(fd, line));
	width = len(line);
	i = 0;
	while (line)
	{
		length++;
		if (len(line) != width)
			return (close_fd(fd, line));
		while (line[i])
		{
			if (line[i] != '0' || line[i] != '1' || line[i] != 'C' &&
			    line[i] != 'E' || line[i] != 'P' || (i < width && line[i] != '\n'))
				return (close_fd(fd, line));
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), width);
}
