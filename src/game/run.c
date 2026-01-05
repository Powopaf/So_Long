/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:21 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/05 10:56:27 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include "data.h"

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img1;
	t_data	img2;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "So_Long");
	mlx_loop(mlx);
	img1.img = mlx_new_image(mlx, 500, 500);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bpp, &img1.length, &img1.endian);
	img2.img = mlx_new_image
}

void	put_pixel(t_data *img, int x, int y, int color
