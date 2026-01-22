/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:36 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/22 13:06:08 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "src/parser/parser.h"
#include "src/game/run.h"
#include "error_msg.h"
#include "gnl/get_next_line.h"

int	check_wall(t_map **map, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 1)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j].obj != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check(t_map **map, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!check_wall(map, width))
		return (0);
	while (i < height)
	{
		if (map[i][0].obj != '1' || map[i][width - 1].obj != '1')
			return (0);
		i++;
	}
	i = height - 1;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j].obj != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_map(t_map **map, size_t height, size_t width)
{
	if (!check(map, height, width))
	{
		free_map(map, height);
		get_next_line(-1);
		write(2, ERR_INVALID_MAP, sizeof(ERR_INVALID_MAP));
		return (0);
	}
	if (!is_playable(map, height, width))
	{
		free_map(map, height);
		get_next_line(-1);
		write(2, "Error:\n Not all collectibles or exit are reachable!\n",
			52);
		return (0);
	}
	return (1);
}

static int	is_valid_map_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	**map;
	size_t	height;
	size_t	width;

	if (argc != 2)
	{
		write(2, ERR_INVALID_ARGS, sizeof(ERR_INVALID_ARGS));
		return (EXIT_FAILURE);
	}
	if (!is_valid_map_extension(argv[1]))
	{
		write(2, ERR_INVALID_MAP, sizeof(ERR_INVALID_MAP));
		return (EXIT_FAILURE);
	}
	map = parse_map(argv[1], &height, &width);
	if (map == NULL)
	{
		write(2, ERR_INVALID_MAP, sizeof(ERR_INVALID_MAP));
		return (EXIT_FAILURE);
	}
	if (!validate_map(map, height, width))
		return (EXIT_FAILURE);
	run(map, width, height);
	return (EXIT_SUCCESS);
}
