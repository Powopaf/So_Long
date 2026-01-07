/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:21 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/07 14:28:56 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

static void	init_frame(t_data	*frame, void *mlx, size_t width, size_t height)
{
	frame->img = mlx_new_image(mlx, width * SCALE, height * SCALE);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp, &frame->length, &frame->endian);
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
}
