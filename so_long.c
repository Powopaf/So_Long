/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:36 by pifourni          #+#    #+#             */
/*   Updated: 2025/12/17 16:19:48 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Invalid number of arguments\n Use: ./so_long <map_path>");
		return (1);
	}
	if (parse_map(argv[1]) != 0)
	{
		perror("Error\n Invalid map");
		return (1);
	}
	return (0);
}
