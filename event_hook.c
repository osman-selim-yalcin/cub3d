#include "cub3d.h"

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