/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:03:39 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/14 11:04:02 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include "../run.h"

int	is_exit_open(t_map **map, size_t width, size_t height)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j].obj == 'C' && map[i][j].has_been_collected == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	find_exit_position(t_mlx *mlx, int *x, int *y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			if (mlx->map[i][j].obj == 'E')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

int	close_window(void *p)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)p;
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_map(mlx->map, mlx->height);
	get_next_line(-1);
	exit(0);
	return (0);
}