/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_play_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:25:00 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/20 14:25:00 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_visited(int **visited, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	free_visited(int **visited, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	**allocate_visited(size_t height, size_t width)
{
	int		**visited;
	size_t	i;

	visited = malloc(sizeof(int *) * height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = malloc(sizeof(int) * width);
		if (!visited[i])
		{
			while (i > 0)
				free(visited[--i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

void	enqueue(t_reach *ctx, int x, int y)
{
	ctx->queue[ctx->rear].x = x;
	ctx->queue[ctx->rear].y = y;
	(ctx->rear)++;
}

int	is_walkable(t_reach *ctx, int x, int y)
{
	if (x < 0 || x >= (int)ctx->width || y < 0 || y >= (int)ctx->height)
		return (0);
	if (ctx->map[y][x].obj == '1' || ctx->visited[y][x])
		return (0);
	return (1);
}
