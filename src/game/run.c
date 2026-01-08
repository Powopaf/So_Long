/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:21 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/08 12:20:36 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

static void	init_frame(t_data	*frame, void *mlx, size_t width, size_t height)
{
	frame->img = mlx_new_image(mlx, width * SCALE, height * SCALE);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp, &frame->length, &frame->endian);
}

static void	render_map(t_data *frame, t_map **map, size_t width, size_t height)
{
 	size_t	i;
	size_t	j;

	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			if (map[i][j].obj == '1')
				square(frame, i, j, WHITE);
			else if (map[i][j].obj == 'C' && map[i][j].has_been_collected == 0)
				collectible(frame, i, j, PURPLE);
			else if (map[i][j].obj == 'E' && map[i][j].is_exit_open == 0)
				triangle(frame, i, j, RED);
			else if (map[i][j].obj == 'E')
				triangle(frame, i, j, GREEN);
			else if (map[i][j].obj == 'P')
				triangle(frame, i, j, CYAN);
			else if (map[i][j].has_player == 1)
				square(frame, i, j, BLUE);
			else
				square(frame, i, j, BLACK);
		}
	}
}

void	run(t_map **map, size_t width, size_t height)
{
	void	*mlx;
	void	*window;
	t_data	frame1;
	t_data	frame2;

	mlx = mlx_init();
	window = mlx_new_window(mlx, width * SCALE, height * SCALE, "So_Long");
	init_frame(&frame1, mlx, width, height);
	init_frame(&frame2, mlx, width, height);
	render_map(&frame1, map, width, height);
	mlx_put_image_to_window(mlx, window, frame1.img, 0, 0);
	mlx_loop(mlx);

}