#include "cub3d.h"

void	synchronize_settings(t_game *game)
{
	game->settings.step_size = game->settings.minimap_scale / 10;
	game->settings.player_size = game->settings.minimap_scale / 4;
	game->settings.ray_len = 2 * game->settings.minimap_scale / 5;
}

int key_event(int keycode, t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	// game->minimap.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	put_floorceil(game);
	if (keycode == 0)
	{
		game->minimap.pa -= 2 * M_PI / 36;
		if (game->minimap.pa < 0)
		{
			game->minimap.pa += 2 * M_PI;
		}
		game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
		game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	}
	if (keycode == 2)
	{
		game->minimap.pa += 2 * M_PI / 36;
		if (game->minimap.pa > 2 * M_PI)
		{
			game->minimap.pa -= 2 * M_PI;
		}
		game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
		game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	}
	if (keycode == 13)
	{
		game->minimap.pos_x += game->minimap.step_offset_x;
		game->minimap.pos_y += game->minimap.step_offset_y;

	}
	if (keycode == 1)
	{
		game->minimap.pos_x -= game->minimap.step_offset_x;
		game->minimap.pos_y -= game->minimap.step_offset_y;
	}
	if (keycode == 46)
	{
		if (game->settings.minimap_scale == 20)
			game->settings.minimap_scale = 120;
		else
			game->settings.minimap_scale = 20;
		synchronize_settings(game);
	}
	if (keycode == 53)
		tmp_exit();
	// printf("keycode %d\n", keycode);
	tmp(game);
	return(1);
}