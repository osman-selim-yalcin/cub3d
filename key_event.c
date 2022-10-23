#include "cub3d.h"

int key_event(int keycode, t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->minimap.addr = mlx_get_data_addr(game->img.img, &game->minimap.bits_per_pixel, &game->minimap.line_length, &game->minimap.endian);
	put_floorceil(game);
	if (keycode == 0)
	{
		game->minimap.pa -= 2 * M_PI / 36;
		if (game->minimap.pa < 0)
		{
			game->minimap.pa += 2 * M_PI;
		}
		game->minimap.pdx = cos(game->minimap.pa) * 2;
		game->minimap.pdy = sin(game->minimap.pa) * 2;
	}
	if (keycode == 2)
	{
		game->minimap.pa += 2 * M_PI / 36;
		if (game->minimap.pa > 2 * M_PI)
		{
			game->minimap.pa -= 2 * M_PI;
		}
		game->minimap.pdx = cos(game->minimap.pa) * 2;
		game->minimap.pdy = sin(game->minimap.pa) * 2;
	}
	if (keycode == 13)
	{
		game->minimap.px += game->minimap.pdx;
		game->minimap.py += game->minimap.pdy;

	}
	if (keycode == 1)
	{
		game->minimap.px -= game->minimap.pdx;
		game->minimap.py -= game->minimap.pdy;
	}
	if (keycode == 53)
		tmp_exit();
	tmp(game);
	return(1);
}