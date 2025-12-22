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

static int	check_line(char *line, size_t width)
{
	size_t	i;

	i = 0;
	while (i <= width)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	check_map(const char *map_path, size_t *width, size_t *height)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	*height = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (close_fd(fd, line), 0);
	*width = ft_strlen(line) - 1;
	while (line)
	{
		if ((ft_strlen(line) - 1 != *width || !check_line(line, *width)))
			return (close_fd(fd, line), 0);
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	return (close_fd(fd, line), 1);
}

static int	build_map(t_map **map, size_t width, size_t height, int fd)
{
	char	*line;
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		i = 0;
		map[j] = malloc(sizeof(t_map) * width);
		if (map[j] == NULL)
			return (free(line), 0);
		i = -1;
		while (++i < width)
		{
			map[j][i].obj = line[i];
			map[j][i].has_been_collected = 0;
			map[j][i].is_exit_open = 0;
			map[j][i].has_player = 0;
		}
		free(line);
	}
	return (1);
}

t_map	**parse_map(const char *map_path, size_t *height)
{
	size_t	width;
	t_map	**map;
	int		fd;

	if (!check_map(map_path, &width, height))
		return (NULL);
	map = malloc(sizeof(t_map *) * (*height));
	if (map == NULL)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	if (!build_map(map, width, *height, fd))
		return (close_fd(fd, NULL), free_map(map, *height), NULL);
	close(fd);
	return (map);
}
