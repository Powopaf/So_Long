/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:58:22 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/07 14:09:15 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_H
# define RUN_H

# include "data.h"
# include "../../minilibx-linux/mlx.h"
# include "../parser/parser.h"

# define SCALE 10

void	run(t_map **map, size_t width, size_t height);

#endif
