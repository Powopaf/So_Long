/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:14:43 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/20 14:25:00 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

void	init_visited(int **visited, size_t height, size_t width);
void	free_visited(int **visited, size_t height);
int		**allocate_visited(size_t height, size_t width);
void	enqueue(t_reach *ctx, int x, int y);
int		is_walkable(t_reach *ctx, int x, int y);

static void	fill_initial_data(t_reach *ctx)
{
	size_t	i;
	size_t	j;

	ctx->total = 0;
	ctx->rear = 0;
	i = 0;
	while (i < ctx->height)
	{
		j = 0;
		while (j < ctx->width)
		{
			if (ctx->map[i][j].has_player)
			{
				enqueue(ctx, j, i);
				ctx->visited[i][j] = 1;
			}
			if (ctx->map[i][j].obj == 'C')
				ctx->total++;
			j++;
		}
		i++;
	}
}

static void	explore_neighbors(t_reach *ctx, int x, int y)
{
	if (is_walkable(ctx, x + 1, y))
	{
		ctx->visited[y][x + 1] = 1;
		enqueue(ctx, x + 1, y);
	}
	if (is_walkable(ctx, x - 1, y))
	{
		ctx->visited[y][x - 1] = 1;
		enqueue(ctx, x - 1, y);
	}
	if (is_walkable(ctx, x, y + 1))
	{
		ctx->visited[y + 1][x] = 1;
		enqueue(ctx, x, y + 1);
	}
	if (is_walkable(ctx, x, y - 1))
	{
		ctx->visited[y - 1][x] = 1;
		enqueue(ctx, x, y - 1);
	}
}

static void	process_queue(t_reach *ctx)
{
	int	front;
	int	x;
	int	y;

	front = 0;
	ctx->collectibles = 0;
	ctx->exit_found = 0;
	while (front < ctx->rear && ctx->rear < (int)(ctx->height * ctx->width))
	{
		x = ctx->queue[front].x;
		y = ctx->queue[front].y;
		if (ctx->map[y][x].obj == 'E')
			ctx->exit_found = 1;
		if (ctx->map[y][x].obj == 'C')
			ctx->collectibles++;
		explore_neighbors(ctx, x, y);
		front++;
	}
}

int	is_playable(t_map **map, size_t height, size_t width)
{
	t_reach	ctx;

	if (!map || height == 0 || width == 0)
		return (0);
	ctx.visited = allocate_visited(height, width);
	if (!ctx.visited)
		return (0);
	ctx.queue = malloc(sizeof(t_queue) * (height * width));
	if (!ctx.queue)
		return (free_visited(ctx.visited, height), 0);
	init_visited(ctx.visited, height, width);
	ctx.map = map;
	ctx.height = height;
	ctx.width = width;
	fill_initial_data(&ctx);
	process_queue(&ctx);
	free_visited(ctx.visited, height);
	free(ctx.queue);
	if (ctx.exit_found && ctx.collectibles == ctx.total)
		return (1);
	return (0);
}
