/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:00:27 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/17 11:00:28 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "../../Get_Next_Line/get_next_line.h"

int		parse_map(const char *map_path);

#endif
