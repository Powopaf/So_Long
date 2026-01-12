/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:19:57 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/09 12:36:54 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "../../../minilibx-linux/mlx.h"
# include "../data.h"
# include "../../../printf/ft_printf.h"
# include <unistd.h>

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

int		event(int keycode, void *p);
int		is_exit_open(t_map **map, size_t width, size_t height);
void	find_exit_position(t_map **map, int *x, int *y, size_t width, size_t height);

#endif 
