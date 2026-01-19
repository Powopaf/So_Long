/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:21 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/19 13:36:37 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

void	render_map(t_data *frame, t_map **map, size_t width, size_t height)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j].has_player == 1)
				square(frame, j * SCALE, i * SCALE, BLUE);
			else if (map[i][j].obj == '1')
				square(frame, j * SCALE, i * SCALE, WHITE);
			else if (map[i][j].obj == 'C' && map[i][j].has_been_collected == 0)
				collectible(frame, j * SCALE, i * SCALE, PURPLE);
			else if (map[i][j].obj == 'E' && map[i][j].is_exit_open == 0)
				triangle(frame, j * SCALE, i * SCALE, RED);
			else if (map[i][j].obj == 'E')
				triangle(frame, j * SCALE, i * SCALE, GREEN);
			else if (map[i][j].obj == 'P')
				triangle(frame, j * SCALE, i * SCALE, CYAN);
			else
				square(frame, j * SCALE, i * SCALE, BLACK);
		}
	}
}

static void	display(t_mlx *mlx)
{
	if (mlx->moves % 2 == 0)
	{
		render_map(&mlx->frame1, mlx->map, mlx->width, mlx->height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame1.img, 0, 0);
	}
	else
	{
		render_map(&mlx->frame2, mlx->map, mlx->width, mlx->height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame2.img, 0, 0);
	}
	mlx_hook(mlx->win, 2, 1L << 0, event, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx);
}

static int	init_mlx(t_mlx *mlx, size_t width, size_t height)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		return (1);
	}
	mlx->win = mlx_new_window(mlx->mlx, width * SCALE,
			height * SCALE, "So_Long");
	if (!mlx->win)
	{
		error_win(*mlx);
		return (1);
	}
	return (0);
}

static int	init_frames(t_mlx *mlx)
{
	if (init_frame(&mlx->frame1, mlx->mlx, mlx->width, mlx->height))
	{
		error_f1(*mlx);
		return (1);
	}
	if (init_frame(&mlx->frame2, mlx->mlx, mlx->width, mlx->height))
	{
		error_f2(*mlx);
		return (1);
	}
	return (0);
}

void	run(t_map **map, size_t width, size_t height)
{
	t_mlx	mlx;

	mlx.map = map;
	mlx.width = width;
	mlx.height = height;
	mlx.moves = 0;
	if (init_mlx(&mlx, width, height))
		return ;
	if (init_frames(&mlx))
		return ;
	display(&mlx);
}
