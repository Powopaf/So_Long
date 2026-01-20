/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:39:29 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/20 13:39:31 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

void	error_win(t_mlx mlx)
{
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	free_map(mlx.map, mlx.height);
	get_next_line(-1);
}

void	error_f1(t_mlx mlx)
{
	mlx_destroy_image(mlx.mlx, mlx.frame1.img);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	free_map(mlx.map, mlx.height);
	get_next_line(-1);
}

void	error_f2(t_mlx mlx)
{
	mlx_destroy_image(mlx.mlx, mlx.frame1.img);
	mlx_destroy_image(mlx.mlx, mlx.frame2.img);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	free_map(mlx.map, mlx.height);
	get_next_line(-1);
}
