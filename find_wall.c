#include "cub3d.h"

int find_wall_vertical(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (ver < 0 || hor < 0)
	{
		return (2);
	}
	if (ver > game->map.length + 1 || hor > game->map.width + 1)
	{
		return (2);
	}
	if (game->map.map[(int)ver][(int)(hor + 0.5)] == '1' || game->map.map[(int)ver][(int)(hor - 0.5)] == '1')
	{

		return (1);
	}
	return (0);
}

int find_wall_horizontal(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (ver < 0 || hor < 0)
	{
		return (2);
	}
	if (ver > game->map.length + 1 || hor > game->map.width + 1)
	{
		return (2);
	}
	if (game->map.map[(int)(ver + 0.5)][(int)(hor)] == '1' || game->map.map[(int)(ver - 0.5)][(int)(hor)] == '1')
	{
		return (1);
	}
	return (0);
}
