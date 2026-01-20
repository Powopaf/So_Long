/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_play.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:25:00 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/20 14:25:00 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_PLAY_H
# define IS_PLAY_H

# include "parser.h"
# include <stdlib.h>

int	is_playable(t_map **map, size_t height, size_t width);

#endif
