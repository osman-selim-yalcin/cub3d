#include "cub3d.h"

int	is_top_num_tmp(char **map, int row, int column)
{
	if (map[row - 1][column] != '2')
		return (1);
	return (0);
}

int	is_left_num_tmp(char **map, int row, int column)
{
	if (map[row][column - 1] != '2')
		return (1);
	return (0);
}

int	is_right_num_tmp(char **map, int row, int column)
{
	if (map[row][column + 1] != '2')
		return (1);
	return (0);
}

int	is_bottom_num_tmp(char **map, int row, int column)
{
	if (map[row + 1][column] != '2')
		return (1);
	return (0);
}
