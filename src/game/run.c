/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:21 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/12 13:32:32 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

static void	init_frame(t_data	*frame, void *mlx, size_t width, size_t height)
{
	frame->img = mlx_new_image(mlx, width * SCALE, height * SCALE);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp, &frame->length, &frame->endian);
}

void	render_map(t_data *frame, t_map **map, size_t width, size_t height)
{
 	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
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
			j++;
		}
		i++;
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
	mlx_hook(mlx->win, 2, 1L<<0, event, mlx);
	mlx_loop(mlx->mlx);
}

void	run(t_map **map, size_t width, size_t height)
{
	t_mlx	 mlx;

	mlx.map = map;
	mlx.width = width;
	mlx.height = height;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, width * SCALE, height * SCALE, "So_Long");
    mlx.moves = 0;
	init_frame(&mlx.frame1, mlx.mlx, width, height);
	init_frame(&mlx.frame2, mlx.mlx, width, height);
	display(&mlx);
}
