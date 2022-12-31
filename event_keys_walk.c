#include "cub3d.h"


void key_a(t_game *game)
{
	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;

	float offset;
	offset = game->player.pos_x + round_double(5 * (cos(deg_to_rad(game->player.direction))));
	game->player.pos_x = offset;
	offset = game->player.pos_y - round_double(5 * (sin(deg_to_rad(game->player.direction))));
	game->player.pos_y = offset;

	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
	game->player.direction -= 90;
	if (game->player.direction < 0)
		game->player.direction += 360;
}

void key_d(t_game *game)
{
	game->player.direction -= 90;
	if (game->player.direction < 0)
		game->player.direction += 360;
	
	
	float offset;
	offset = game->player.pos_x + round_double(5 * (cos(deg_to_rad(game->player.direction))));
	game->player.pos_x = offset;
	offset = game->player.pos_y - round_double(5 * (sin(deg_to_rad(game->player.direction))));
	game->player.pos_y = offset;

	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
	
	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;
}

void key_w(t_game *game)
{
	float offset;
	offset = game->player.pos_x + round_double(10 * (cos(deg_to_rad(game->player.direction))));
		game->player.pos_x = offset;
	offset = game->player.pos_y - round_double(10 * (sin(deg_to_rad(game->player.direction))));
		game->player.pos_y = offset;
	
	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
}

void key_s(t_game *game)
{
	float offset;
	offset = game->player.pos_x - round_double(10 * (cos(deg_to_rad(game->player.direction))));
		game->player.pos_x = offset;
	offset = game->player.pos_y + round_double(10 * (sin(deg_to_rad(game->player.direction))));
		game->player.pos_y = offset;

	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
}