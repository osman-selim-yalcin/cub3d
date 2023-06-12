#include "cub3d.h"

int	is_bottom_valid(char **map, int row, int column)
{
	if (map[row + 1] == NULL)
		return (1);
	if (map[row + 1][column] == '0' || map[row + 1][column] == 'N' || \
		map[row + 1][column] == 'S' || map[row + 1][column] == 'E' || \
		map[row + 1][column] == 'W' || map[row + 1][column] == 'C')
		return (0);
	return (1);
}

int	is_top_valid(char **map, int row, int column)
{
	if (row == 0)
		return (1);
	if (map[row - 1][column] == '0' || map[row - 1][column] == 'N' || \
		map[row - 1][column] == 'S' || map[row - 1][column] == 'E' || \
		map[row - 1][column] == 'W' || map[row - 1][column] == 'C')
		return (0);
	return (1);
}

int	is_right_valid(char **map, int row, int column)
{
	if (map[row][column + 1] == '\0')
		return (1);
	if (map[row][column + 1] == '0' || map[row][column + 1] == 'N' || \
		map[row][column + 1] == 'S' || map[row][column + 1] == 'E' || \
		map[row][column + 1] == 'W' || map[row][column + 1] == 'C')
		return (0);
	return (1);
}

int	is_left_valid(char **map, int row, int column)
{
	if (column == 0)
		return (1);
	if (map[row][column - 1] == '0' || map[row][column - 1] == 'N' || \
		map[row][column - 1] == 'S' || map[row][column - 1] == 'E' || \
		map[row][column - 1] == 'W' || map[row][column - 1] == 'C')
		return (0);
	return (1);
}

int	check_all_twos(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2' && (!is_left_valid(map, i, j) || !is_right_valid(map, i, j) \
				|| !is_top_valid(map, i, j) || !is_bottom_valid(map, i, j)))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}