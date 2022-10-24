#include "cub3d.h"

void key_a(t_game *game)
{
	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;
	if (direction_angle(game) == 1)
	{
		game->player.pos_x = game->player.pos_x + round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 2)
	{
		game->player.pos_x = game->player.pos_x - round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 3)
	{
		game->player.pos_x = game->player.pos_x - round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 4)
	{
		game->player.pos_x = game->player.pos_x + round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	game->player.direction -= 90;
	if (game->player.direction < 0)
		game->player.direction += 360;
}

void key_d(t_game *game)
{
	game->player.direction -= 90;
	if (game->player.direction < 0)
		game->player.direction += 360;
	if (direction_angle(game) == 1)
	{
		game->player.pos_x = game->player.pos_x + round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 2)
	{
		game->player.pos_x = game->player.pos_x - round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 3)
	{
		game->player.pos_x = game->player.pos_x - round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 4)
	{
		game->player.pos_x = game->player.pos_x + round_double(5 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(5 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;
}

void key_w(t_game *game)
{
	if (direction_angle(game) == 1)
	{
		game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 2)
	{
		game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 3)
	{
		game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 4)
	{
		game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	game->minimap.pos_x += game->minimap.step_offset_x;
	game->minimap.pos_y += game->minimap.step_offset_y;
}

void key_s(t_game *game)
{
	if (direction_angle(game) == 1)
	{
		game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 2)
	{
		game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 3)
	{
		game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	if (direction_angle(game) == 4)
	{
		game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
		game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
	}
	game->minimap.pos_x -= game->minimap.step_offset_x;
	game->minimap.pos_y -= game->minimap.step_offset_y;
}