#include "cub3d.h"

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
	if (game->player.ray_absoulete >= 0 && game->player.ray_absoulete < 90)
		return (1);
	if (game->player.ray_absoulete >= 90 && game->player.ray_absoulete < 180)
		return (2);
	if (game->player.ray_absoulete >= 180 && game->player.ray_absoulete < 270)
		return (3);
	if (game->player.ray_absoulete >= 270 && game->player.ray_absoulete < 360)
		return (4);
	return (5);
}
