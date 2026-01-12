#include "key.h"
#include "../run.h"

int	is_exit_open(t_map **map, size_t width, size_t height)
{
	size_t	i;
	size_t	j;

	i = 0;

	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j].obj == 'C' && map[i][j].has_been_collected == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	find_exit_position(t_map **map, int *x, int *y, size_t width, size_t height)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j].obj == 'E')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}
