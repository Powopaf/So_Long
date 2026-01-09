/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:19:51 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/09 11:39:46 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include <stdlib.h>

int	close_win(int keycode, void *p)
{
	t_mlx	mlx;

	mlx = *(t_mlx *)p;
	mlx_destroy_window(mlx.mlx, mlx.win);
	exit(0);
	return (keycode);
}
