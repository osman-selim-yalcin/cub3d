#include "cub3d.h"

int mouse_move(int x, int y, t_game *game)
{
	(void)y;
	int a = SCREEN_WID / 2 - x;
	game->player.direction += (int)SENS * (int)a / 20;
	game->minimap.pa += deg_to_rad((int)SENS * (int)a / 20);
	if (game->player.direction >= 360)
	{
		game->minimap.pa -= 2 * M_PI;
		game->player.direction -= 360;
	}
	else if (game->player.direction < 0)
	{
		game->minimap.pa += 2 * M_PI;
		game->player.direction += 360;
	}
	mlx_mouse_move(game->libx.win, SCREEN_WID / 2, SCREEN_LEN / 2);
	return (0);
}

int	temporary_killer(int code, int x, int y, t_game *game) // to be changed
{
	(void)x;
	(void)y;
	if (code == 1)
	{
		kill_all(game);
	}
	else if (code == 2)
	{
		revive_all(game);
	}
	printf("code %d\n", code);
	return (0);
}