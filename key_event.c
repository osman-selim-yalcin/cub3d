#include "cub3d.h"

void key_e(t_game *game)
{
	int left;
	int right;
	int posx_100;
	int posy_100;

	left = game->player.direction + D_FOV;
	right = game->player.direction + D_FOV;
	posx_100 = game->player.pos_x / 100;
	posy_100 = game->player.pos_y / 100;
	if (degree_angle(left) == 1 || degree_angle(right) == 1)
	{
		if (game->map.map[posy_100 - 1][posx_100] == '1' || game->map.map[posy_100][posx_100 + 1] == '1' || game->map.map[posy_100 - 1][posx_100 + 1] == '1')
		{
			printf("wall\n");
		}
	}
	if (degree_angle(left) == 2 || degree_angle(right) == 2)
	{
		if (game->map.map[posy_100 - 1][posx_100] == '1' || game->map.map[posy_100][posx_100 - 1] == '1' || game->map.map[posy_100 - 1][posx_100 - 1] == '1')
		{
			printf("wall 2\n");
		}
	}
	if (degree_angle(left) == 3 || degree_angle(right) == 3)
	{
		if (game->map.map[posy_100 + 1][posx_100] == '1' || game->map.map[posy_100][posx_100 - 1] == '1' || game->map.map[posy_100 + 1][posx_100 - 1] == '1')
		{
			printf("wall 3\n");
		}
	}
	if (degree_angle(right) == 4 || degree_angle(right) == 4)
	{
		if (game->map.map[posy_100 + 1][posx_100] == '1' || game->map.map[posy_100][posx_100 + 1] == '1' || game->map.map[posy_100 + 1][posx_100 + 1] == '1')
		{
			printf("wall 4\n");
		}
	}
}

void	set_enemy_mini_position(t_game *game)
{
	t_enemy *current_enemy;

	current_enemy = game->enemy;
	while (current_enemy != NULL)
	{
		if (current_enemy->alive == 0)
		{
			current_enemy = current_enemy->next;
			continue ;
		}
		current_enemy->mini_x = (current_enemy->posx - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
		current_enemy->mini_y = current_enemy->posy / 100 * game->settings.minimap_scale;
		current_enemy = current_enemy->next;
	}
}

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
	if (keycode == 124) // right
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
	if (keycode == 0) //5 yaptım çok hızlı gibiydi
		key_a(game);
	if (keycode == 2)//5 yaptım çok hızlı gibiydi
		key_d(game);
	if (keycode == 13)
		key_w(game);
	if (keycode == 1)
		key_s(game);
	if (keycode == 53)
		tmp_exit();
	if (keycode == 14)
		key_e(game);
	if (keycode == 46) //m
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
	if (keycode == 53)
		tmp_exit();
	return(0);
}