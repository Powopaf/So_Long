/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:58:22 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/08 12:18:01 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_H
# define RUN_H

# include "data.h"
# include "../../minilibx-linux/mlx.h"
# include "../parser/parser.h"

# define SCALE 10
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define CYAN 0x0000FFFF
# define RED 0x00FF0000
# define PURPLE 0x00800080
# define BLUE 0x000000FF

void	run(t_map **map, size_t width, size_t height);
void	square(t_data *frame, int x, int y, unsigned int color);
void	collectible(t_data *frame, int x, int y, unsigned int color);
void	triangle(t_data *frame, int x, int y, unsigned int color);

#endif
