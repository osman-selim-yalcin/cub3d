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
	if (keycode == 123) // left
	{
		game->player.direction += 10;
		if (game->player.direction >= 360)
			game->player.direction -= 360;
		game->minimap.pa += 2 * M_PI / 36;
		if (game->minimap.pa > 2 * M_PI)
		{
			game->minimap.pa -= 2 * M_PI;
		}

		game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
		game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	}
	else if (keycode == 124) // right
	{
		game->player.direction -= 10;
		if (game->player.direction < 0)
			game->player.direction += 360;
		game->minimap.pa -= 2 * M_PI / 36;
		if (game->minimap.pa < 0)
		{
			game->minimap.pa += 2 * M_PI;
		}
		game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
		game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	}
	else if (keycode == 126)
	{
		game->mouse_horizontal += 30;
		if (game->mouse_horizontal > (SCREEN_LEN / 2))
			game->mouse_horizontal = (SCREEN_LEN / 2);
	}
	else if (keycode == 125)
	{
		game->mouse_horizontal -= 30;
		if (game->mouse_horizontal < -(SCREEN_LEN / 2))
			game->mouse_horizontal = -(SCREEN_LEN / 2);
	}
	else if (keycode == 0) //5 yaptım çok hızlı gibiydi
		key_a(game);
	else if (keycode == 2)//5 yaptım çok hızlı gibiydi
		key_d(game);
	else if (keycode == 13)
		key_w(game);
	else if (keycode == 1)
		key_s(game);
	else if (keycode == 53)
		tmp_exit();
	else if (keycode == 14)
		key_e(game);
	else if (keycode == 46) //m
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