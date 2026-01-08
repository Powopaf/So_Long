/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:36 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/08 13:55:24 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "src/parser/parser.h"
#include "src/game/run.h"
#include "error_msg.h"

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
	map = parse_map(argv[1], &height, &width);
	if (map == NULL)
	{
		write(2, ERR_INVALID_MAP, sizeof(ERR_INVALID_MAP));
		return (EXIT_FAILURE);
	}
	run(map, width, height);
	free_map(map, height);
	return (EXIT_SUCCESS);
}
