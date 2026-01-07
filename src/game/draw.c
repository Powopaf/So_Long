/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:47:59 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/07 16:54:55 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

/*
 * A square in the game is of Size SCALE define in run.h
 * everything should then fit in a SCALE - 1 square do leava a 1 pixel border
 * around the edge
 *
 * was first design for a SCALE of 10 some form may not be center and cause if
 *issue if change
 */

static void	pixel(t_data *frame, int x, int y, unsigned int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->length + x * (frame->bpp / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data	*frame, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCALE - 1)
	{
		j = 0;
		while (j < SCALE - 1)
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

	center = SCALE / 2;
	row = 0;
	while (row < SCALE - 1)
	{
		if (row - center < 0)
			width = SCALE - 1 - 2 * -(row - center);
		else
			width = SCALE - 1 - 2 * (row - center);
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

void	triangle(t_data *frame, int x, int y, unsigned int color)
{
	int	i;
	int	j;
	int len;

	i = 0;
	len = 1;
	while (i < SCALE - 1)
	{
		j = 0;
		while (j < len)
		{
			pixel(frame, x + i + 2, y + j, color);
			j++;
		}
		i++;
		if (i > 4)
			len--;
		else
			len++;
	}
}
