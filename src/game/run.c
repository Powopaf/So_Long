/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:21 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/09 11:40:22 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

static void	init_frame(t_data	*frame, void *mlx, size_t width, size_t height)
{
	frame->img = mlx_new_image(mlx, height * SCALE, width * SCALE);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp, &frame->length, &frame->endian);
}

static void	render_map(t_data *frame, t_map **map, size_t width, size_t height)
{
 	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j].obj == '1')
				square(frame, i * SCALE, j * SCALE, WHITE);
			else if (map[i][j].obj == 'C' && map[i][j].has_been_collected == 0)
				collectible(frame, i * SCALE, j * SCALE, PURPLE);
			else if (map[i][j].obj == 'E' && map[i][j].is_exit_open == 0)
				triangle(frame, i * SCALE, j * SCALE, RED);
			else if (map[i][j].obj == 'E')
				triangle(frame, i * SCALE, j * SCALE, GREEN);
			else if (map[i][j].obj == 'P')
				triangle(frame, i * SCALE, j * SCALE, CYAN);
			else if (map[i][j].has_player == 1)
				square(frame, i * SCALE, j * SCALE, BLUE);
			else
				square(frame, i * SCALE, j * SCALE, BLACK);
			j++;
		}
		i++;
	}
}

void	run(t_map **map, size_t width, size_t height)
{
	t_mlx	 mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, height * SCALE, width * SCALE, "So_Long");
	init_frame(&mlx.frame1, mlx.mlx, width, height);
	init_frame(&mlx.frame2, mlx.mlx, width, height);
	render_map(&mlx.frame1, map, width, height);
	mlx.curr_frame = 1;
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.frame1.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	mlx_loop(mlx.mlx);

}
