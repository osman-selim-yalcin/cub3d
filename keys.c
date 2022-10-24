#include "cub3d.h"

void key_a(t_game *game)
{
	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;
	game->player.pos_x = game->player.pos_x + round_double(5 * (cos(deg_to_rad(game->player.direction))));
	game->player.pos_y = game->player.pos_y - round_double(5 * (sin(deg_to_rad(game->player.direction))));

	game->player.direction -= 90;
	if (game->player.direction < 0)
		game->player.direction += 360;
}

void key_d(t_game *game)
{
	game->player.direction -= 90;
	game->minimap.pa -= M_PI / 2;
	if (game->player.direction < 0)
	{
		game->minimap.pa += M_PI * 2;
		game->player.direction += 360;
	}
	game->player.pos_x = game->player.pos_x + round_double(5 * (cos(deg_to_rad(game->player.direction))));
	game->player.pos_y = game->player.pos_y - round_double(5 * (sin(deg_to_rad(game->player.direction))));
	game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
	game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	game->minimap.pos_x += game->minimap.step_offset_x;
	game->minimap.pos_y += game->minimap.step_offset_y;
	game->player.direction += 90;
	game->minimap.pa += M_PI / 2;
	if (game->player.direction >= 360)
	{
		game->minimap.pa -= M_PI * 2;
		game->player.direction -= 360;
	}
	game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
	game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
}

void key_w(t_game *game)
{
	game->player.pos_x = game->player.pos_x + round_double(10 * (cos(deg_to_rad(game->player.direction))));
	game->player.pos_y = game->player.pos_y - round_double(10 * (sin(deg_to_rad(game->player.direction))));
	game->minimap.pos_x += game->minimap.step_offset_x;
	game->minimap.pos_y += game->minimap.step_offset_y;
}

void key_s(t_game *game)
{
	game->player.pos_x = game->player.pos_x - round_double(10 * (cos(deg_to_rad(game->player.direction))));
	game->player.pos_y = game->player.pos_y + round_double(10 * (sin(deg_to_rad(game->player.direction))));
	game->minimap.pos_x -= game->minimap.step_offset_x;
	game->minimap.pos_y -= game->minimap.step_offset_y;
}