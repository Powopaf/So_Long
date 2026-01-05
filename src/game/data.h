/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:37:06 by pifourni          #+#    #+#             */
/*   Updated: 2026/01/05 10:45:09 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_data;

#endif
