/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:36:37 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/19 13:36:37 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

int	init_frame(t_data *frame, void *mlx, size_t width, size_t height)
{
	frame->img = mlx_new_image(mlx, width * SCALE, height * SCALE);
	if (!frame->img)
		return (1);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp,
			&frame->length, &frame->endian);
	if (!frame->addr)
		return (1);
	return (0);
}
