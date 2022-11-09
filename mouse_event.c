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

void	set_idle_state(t_game *game)
{
	static int	counter;

	game->enemy_idle_state = counter / 3;
	++counter;
	if (counter == 21)
		counter = 0;
}

int hook_event(t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	get_enemy(game);
	enemy_walk(game);
	start(game);
	display_minimap(game);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
	set_idle_state(game);
	return (0);
}