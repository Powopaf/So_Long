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
# include "../../gnl/get_next_line.h"
# include "../../libft/libft.h"

typedef struct s_parser
{
	int	has_exit;
	int	has_entry;
	int	has_collectible;
}	t_parser;

typedef struct s_map
{
	char	obj;
	int		has_been_collected;
	int		is_exit_open;
	int		has_player;
}	t_map;

t_map	**parse_map(const char *map_path, size_t *height, size_t *width);
void	close_fd(int fd, char *line);
void	free_map(t_map **map, size_t height);
int		check_line(char *line, size_t width, t_parser *parser);
void	assign_map_object(t_map *map_cell, char obj);

#endif
