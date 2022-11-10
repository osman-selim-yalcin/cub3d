#include "cub3d.h"

int player_collision(t_game *game, float x, float y)
{
	t_enemy *tmp_enemy;

	tmp_enemy = game->enemy;
	while (game->enemy)
	{
		if (hypot(game->enemy->posx - x, game->enemy->posy - y) < 80 && game->enemy->alive == 1)
		{
			game->enemy = tmp_enemy;
			return (0);
		}
		game->enemy = game->enemy->next;
	}
	game->enemy = tmp_enemy;
	if (game->map.map[(int)(y)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x + 20)/ 100] != '1')
	{
		if (game->map.map[(int)(y + 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x + 20)/ 100] != '1')
		{
			if (game->map.map[(int)(y - 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x + 20)/ 100] != '1')
			{
				return (1);
			}
		}
	}
	return (0);
}

void key_a(t_game *game)
{
	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;

	float offset;
	offset = game->player.pos_x + round_double(5 * (cos(deg_to_rad(game->player.direction))));
	if (game->map.map[(int)game->player.pos_y / 100][(int)(offset + 20) / 100] != '1' && player_collision(game, offset,game->player.pos_y))
	{
		game->player.pos_x = offset;
	}
	offset = game->player.pos_y - round_double(5 * (sin(deg_to_rad(game->player.direction))));
	if (game->map.map[(int)(offset + 20) / 100][(int)(game->player.pos_x) / 100] != '1' && player_collision(game, game->player.pos_x, offset))
	{
		game->player.pos_y = offset;
	}

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
	if (game->map.map[(int)game->player.pos_y / 100][(int)(offset + 20) / 100] != '1' && player_collision(game, offset,game->player.pos_y))
	{
		game->player.pos_x = offset;
	}
	offset = game->player.pos_y - round_double(5 * (sin(deg_to_rad(game->player.direction))));
	if (game->map.map[(int)(offset + 20) / 100][(int)(game->player.pos_x) / 100] != '1' && player_collision(game, game->player.pos_x, offset))
	{
		game->player.pos_y = offset;
	}
	
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
	if (game->map.map[(int)game->player.pos_y  / 100][(int)(offset + 20) / 100] != '1' && player_collision(game, offset,game->player.pos_y))
	{
		game->player.pos_x = offset;
	}
	offset = game->player.pos_y - round_double(10 * (sin(deg_to_rad(game->player.direction))));
	if (game->map.map[(int)(offset + 20) / 100][(int)(game->player.pos_x) / 100] != '1' && player_collision(game, game->player.pos_x, offset))
	{
		game->player.pos_y = offset;
	}
	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
}

void key_s(t_game *game)
{
	float offset;
	offset = game->player.pos_x - round_double(10 * (cos(deg_to_rad(game->player.direction))));
	if (game->map.map[(int)game->player.pos_y / 100][(int)(offset + 20) / 100] != '1' && player_collision(game, offset,game->player.pos_y))
	{
		game->player.pos_x = offset;
	}
	offset = game->player.pos_y + round_double(10 * (sin(deg_to_rad(game->player.direction))));
	if (game->map.map[(int)(offset + 20) / 100][(int)(game->player.pos_x) / 100] != '1' && player_collision(game, game->player.pos_x, offset))
	{
		game->player.pos_y = offset;
	}
	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
}