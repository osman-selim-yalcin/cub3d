#include "cub3d.h"

int	degree_angle(int degree)
{
	if (degree >= 0 && degree < 90)
		return (1);
	if (degree >= 90 && degree < 180)
		return (2);
	if (degree >= 180 && degree < 270)
		return (3);
	if (degree >= 270 && degree < 360)
		return (4);
	return (0);
}

int	direction_angle(t_game *game)
{
	if (game->player.direction >= 0 && game->player.direction < 90)
		return (1);
	if (game->player.direction >= 90 && game->player.direction < 180)
		return (2);
	if (game->player.direction >= 180 && game->player.direction < 270)
		return (3);
	if (game->player.direction >= 270 && game->player.direction < 360)
		return (4);
	return (0);
}

int	ray_angle(t_game *game)
{
	if (game->player.ray_abs >= 0 && game->player.ray_abs < 90)
		return (1);
	if (game->player.ray_abs >= 90 && game->player.ray_abs < 180)
		return (2);
	if (game->player.ray_abs >= 180 && game->player.ray_abs < 270)
		return (3);
	if (game->player.ray_abs >= 270 && game->player.ray_abs < 360)
		return (4);
	return (5);
}
