#include "run.h"

int	end_game(t_mlx *mlx)
{
	ft_printf("Congratulations! You've collected all items and reached the exit in %d moves!\n", mlx->moves);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->frame1.img);
	mlx_destroy_image(mlx->mlx, mlx->frame2.img);
	exit(0);	
	return (2);
}