/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:37:06 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/09 11:10:13 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

# include "../parser/parser.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	frame1;
	t_data	frame2;
	int 	moves;
	t_map	**map;
	
} t_mlx;

#endif
