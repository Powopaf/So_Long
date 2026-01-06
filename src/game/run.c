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
#include <unistd.h>
#include <sys/time.h>

void	put_pixel(t_data *img, int x, int y, int color);
void	draw_square(t_data *img, int x, int y, int size, int color);
void	clear_image(t_data *img, int color);

void render(t_data *img)
{
	static int i = 0;
	// Example rendering function
	draw_square(img, 0, 0, i, 0x00FF00); // Draw a green square
	i += 10;
}

typedef struct s_loop_ctx
{
	void	*mlx;
	void	*win;
	t_data	*img1;
	t_data	*img2;
	int		use_img1;
	int		frames;
	long	last_ms;
} 	t_loop_ctx;

static long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

static int	loop_tick(void *param)
{
	t_loop_ctx	*ctx;
	t_data		*dst;
	long		ms;

	ctx = (t_loop_ctx *)param;
	if (ctx->frames >= 500)
		return (0);
	ms = now_ms();
	if (ms - ctx->last_ms < 1000)
		return (0);
	ctx->last_ms = ms;
	dst = ctx->img2;
	if (ctx->use_img1)
		dst = ctx->img1;
	clear_image(dst, 0x00000000);
	render(dst);
	mlx_put_image_to_window(ctx->mlx, ctx->win, dst->img, 0, 0);
	ctx->use_img1 = !ctx->use_img1;
	ctx->frames++;
	return (0);
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img1;
	t_data	img2;
	t_loop_ctx	ctx;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "So_Long");
	img1.img = mlx_new_image(mlx, 500, 500);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bpp, &img1.length, &img1.endian);
	img2.img = mlx_new_image(mlx, 500, 500);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bpp, &img2.length, &img2.endian);
	clear_image(&img1, 0x00000000);
	render(&img1);
	clear_image(&img2, 0x00000000);
	mlx_put_image_to_window(mlx, mlx_win, img1.img, 0, 0);

	ctx.mlx = mlx;
	ctx.win = mlx_win;
	ctx.img1 = &img1;
	ctx.img2 = &img2;
	ctx.use_img1 = 0;
	ctx.frames = 1;
	ctx.last_ms = now_ms() - 1000;
	mlx_loop_hook(mlx, loop_tick, &ctx);

	mlx_loop(mlx);
	return (0);
}

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	clear_image(t_data *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

