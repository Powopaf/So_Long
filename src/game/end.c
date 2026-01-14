/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:01:08 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/14 11:02:15 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"
#include "../../gnl/get_next_line.h"

int	end_game(t_mlx *mlx)
{
	ft_printf("Congratulations! You've reached the exit in %d moves!\n",
		mlx->moves);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->frame1.img);
	mlx_destroy_image(mlx->mlx, mlx->frame2.img);
	free_map(mlx->map, mlx->height);
	get_next_line(-1);
	exit(0);
	return (2);
}
