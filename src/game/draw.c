/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:47:59 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/07 16:04:21 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

static void	pixel(t_data *frame, int x, int y, unsigned int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->length + x * (frame->bpp / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data	*frame, int x, int y, int size, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel(frame, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	collectible(t_data *frame, int x, int y, unsigned int color)
{
	int	row;
	int	col;
	int	center;
	int	width;
	int	start_x;

	center = 4;
	row = 0;
	while (row < 9)
	{
		if (row - center < 0)
			width = 9 - 2 * -(row - center);
		else
			width = 9 - 2 * (row - center);
		start_x = center - width / 2;
		col = 0;
		while (col < width)
		{
			pixel(frame, x + start_x + col, y + row, color);
			col++;
		}
		row++;
	}
}
