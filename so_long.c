/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:36 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/17 16:19:48 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "src/parser/parser.h"
#include "error_msg.h"

int main(int argc, char **argv)
{
	t_map	**map;
	size_t	height;

	if (argc != 2)
	{
		write(2, ERR_INVALID_ARGS, sizeof(ERR_INVALID_ARGS));
		return (1);
	}
	map = parse_map(argv[1], &height);
	if (map == NULL)
	{
		write(2, ERR_INVALID_MAP, sizeof(ERR_INVALID_MAP));
		return (1);
	}
	free_map(map, height);
	return (0);
}
