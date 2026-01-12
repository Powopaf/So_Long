/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:24:45 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/22 14:24:47 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_line(char *line, size_t width, t_parser *parser)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		if (line[i] == 'C')
			parser->has_collectible += 1;
		else if (line[i] == 'E')
			parser->has_exit += 1;
		else if (line[i] == 'P')
			parser->has_entry += 1;
		else if (line[i] != '0' && line[i] != '1' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	assign_map_object(t_map *map_cell, char obj)
{
	map_cell->obj = obj;
	map_cell->has_been_collected = 0;
	map_cell->is_exit_open = 0;
	if (obj == 'P')
		map_cell->has_player = 1;
	else
		map_cell->has_player = 0;
}

void	close_fd(int fd, char *line)
{
	if (line)
		free(line);
	close(fd);
}

void	free_map(t_map **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
