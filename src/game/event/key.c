/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:19:51 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/09 12:40:40 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include "../run.h"

static int	edit_map(t_mlx *mlx, int x, int y)
{
	int	exit_x;
	int	exit_y;

	if (mlx->map[x][y].obj == 'C')
	{
		mlx->map[x][y].has_been_collected = 1;
		mlx->map[x][y].obj = '0';
	}
	else if (is_exit_open(mlx->map, mlx->width, mlx->height))
	{
		find_exit_position(mlx->map, &exit_x, &exit_y, mlx->width, mlx->height);
		mlx->map[exit_x][exit_y].is_exit_open = 1;
		if (x == exit_x && y == exit_y)
			return (end_game(mlx));
	}
	return (1);
}


static int	assign_new_position(t_mlx *mlx, int x, int y, int direction)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (direction == KEY_UP)
		dx = -1;
	else if (direction == KEY_DOWN)
		dx = 1;
	else if (direction == KEY_LEFT)
		dy = -1;
	else if (direction == KEY_RIGHT)
		dy = 1;
	if ((dx != 0 || dy != 0) && mlx->map[x + dx][y + dy].obj != '1')
	{
		mlx->map[x + dx][y + dy].has_player = 1;
		mlx->map[x][y].has_player = 0;
		return (edit_map(mlx, x + dx, y + dy));
	}
	return (0);
}

static int	move_player(t_mlx *mlx, int direction)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j].obj)
		{
			if (mlx->map[i][j].has_player == 1)
				return (assign_new_position(mlx, i, j, direction));
			j++;
		}
		i++;
	}
	return (0);
}

void	move_and_render(t_mlx *mlx, int moved)
{
	if (moved)
	{
		mlx->moves += 1;
		ft_printf("Moves: %d\n", mlx->moves);
		if (mlx->moves % 2 == 0)
		{
			render_map(&mlx->frame1, mlx->map, mlx->width, mlx->height);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame1.img, 0, 0);
		}
		else
		{
			render_map(&mlx->frame2, mlx->map, mlx->width, mlx->height);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame2.img, 0, 0);
		}
	}
}

int	event(int keycode, void *p)
{
	t_mlx	*mlx;
	int		moved;

	moved = 0;
	mlx = (t_mlx *)p;
	if (keycode == KEY_UP)
		moved = move_player(mlx, KEY_UP);
	else if (keycode == KEY_DOWN)
		moved = move_player(mlx, KEY_DOWN);
	else if (keycode == KEY_LEFT)
		moved = move_player(mlx, KEY_LEFT);
	else if (keycode == KEY_RIGHT)
		moved = move_player(mlx, KEY_RIGHT);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	move_and_render(mlx, moved);
	return (0);
}
