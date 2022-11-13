#include "cub3d.h"

void	synchronize_settings(t_game *game)
{
	game->settings.step_size = game->settings.minimap_scale / 10;
	game->settings.player_size = game->settings.minimap_scale / 4;
	game->settings.ray_len = 2 * game->settings.minimap_scale / 5;
	game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
	game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
}

int key_event(int keycode, t_game *game)
{
	if (keycode == 123)
		game->settings.key_left = 1;
	else if (keycode == 124)
		game->settings.key_right = 1;
	else if (keycode == 126)
		game->settings.key_up = 1;
	else if (keycode == 125)
		game->settings.key_down = 1;
	else if (keycode == 0)
		game->settings.key_a = 1;
	else if (keycode == 2)
		game->settings.key_d= 1;
	else if (keycode == 13)
		game->settings.key_w = 1;
	else if (keycode == 1)
		game->settings.key_s = 1;
	else if (keycode == 53)
		tmp_exit();
	else if (keycode == 14)
		key_e(game);
	else if (keycode == 46)
	{
		if (game->settings.minimap_scale == game->minimap.full_scale)
		{
			game->settings.minimap_scale /= 5;
			game->minimap.shift_x = 0;
			game->minimap.shift_y = 0;
		}
		else
		{
			game->settings.minimap_scale = game->minimap.full_scale;
			game->minimap.shift_x = ((SCREEN_WID - game->minimap.full_scale * (game->map.total_column - game->minimap.empty_column - game->minimap.empty_column2)) - game->minimap.full_scale) / 2;
			game->minimap.shift_y = ((SCREEN_LEN - (game->map.length + 1) * game->minimap.full_scale) - game->minimap.full_scale) / 2;
		}
		synchronize_settings(game);
	}
	else if (keycode == 53)
		tmp_exit();
	return(0);
}

int key_event_2(int keycode, t_game *game)
{
	if (keycode == 0)
		game->settings.key_a = 0;
	else if (keycode == 1)
		game->settings.key_s = 0;
	else if (keycode == 2)
		game->settings.key_d= 0;
	else if (keycode == 13)
		game->settings.key_w = 0;
	else if (keycode == 123)
		game->settings.key_left = 0;
	else if (keycode == 124)
		game->settings.key_right = 0;
	else if (keycode == 126)
		game->settings.key_up = 0;
	else if (keycode == 125)
		game->settings.key_down = 0;
	
	return(0);
}