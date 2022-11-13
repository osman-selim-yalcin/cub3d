#include "cub3d.h"

int mouse_move(int x, int y, t_game *game)
{
	int b;
	b = (y - (SCREEN_LEN / 2)) / 3;
	if ((game->mouse_horizontal - b > -(SCREEN_LEN / 2)) && (game->mouse_horizontal - b < SCREEN_LEN / 2))
		game->mouse_horizontal -= b;

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
