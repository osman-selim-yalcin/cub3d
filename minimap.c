#include "cub3d.h"

void draw_64(int x, int y, t_game *game)
{
	int x2 = 0;
	int y2 = 0;
	if (game->map.map[y][x] == '1')
	{
		while (x2 < game->settings.minimap_scale)
		{
			y2 = 0;
			while (y2 < game->settings.minimap_scale)
			{
				if (x2 < game->settings.minimap_scale / 10 || x2 >= game->settings.minimap_scale - (game->settings.minimap_scale / 10) || \
					y2 < game->settings.minimap_scale / 10 || y2 >= game->settings.minimap_scale - (game->settings.minimap_scale / 10))//grid frame
					my_mlx_pixel_put(game, (x - game->minimap.empty_column) * game->settings.minimap_scale + x2 + game->minimap.shift_x, y * game->settings.minimap_scale + y2 + game->minimap.shift_y, 0x007b2d26);
				else//wall
					my_mlx_pixel_put(game, (x - game->minimap.empty_column) * game->settings.minimap_scale + x2 + game->minimap.shift_x, y * game->settings.minimap_scale + y2 + game->minimap.shift_y, 0x00d7c9aa);
				y2++;
			}
			x2++;
		}
	}
	else if (game->map.map[y][x] == 'C')
	{
		while (x2 < game->settings.minimap_scale)
		{
			y2 = 0;
			while (y2 < game->settings.minimap_scale)
			{
				if (x2 < game->settings.minimap_scale / 10 || x2 >= game->settings.minimap_scale - (game->settings.minimap_scale / 10) || \
					y2 < game->settings.minimap_scale / 10 || y2 >= game->settings.minimap_scale - (game->settings.minimap_scale / 10))//grid frame
					my_mlx_pixel_put(game, (x - game->minimap.empty_column) * game->settings.minimap_scale + x2 + game->minimap.shift_x, y * game->settings.minimap_scale + y2 + game->minimap.shift_y, 0x00FF6B00);
				else//wall
					my_mlx_pixel_put(game, (x - game->minimap.empty_column) * game->settings.minimap_scale + x2 + game->minimap.shift_x, y * game->settings.minimap_scale + y2 + game->minimap.shift_y, 0x009ea3b0);
				y2++;
			}
			x2++;
		}
	}
	else if (game->map.map[y][x] != '2')//background
	{
		while (x2 < game->settings.minimap_scale)
		{
			y2 = 0;
			while (y2 < game->settings.minimap_scale)
			{
				my_mlx_pixel_put(game, (x - game->minimap.empty_column) * game->settings.minimap_scale + x2 + game->minimap.shift_x, y * game->settings.minimap_scale + y2 + game->minimap.shift_y, 0x00000000);
				y2++;
			}
			x2++;
		}
	}
}

void draw_map(t_game *game)
{
	int x = 1;
	int y;
	while (x < game->minimap.mapx)
	{
		y = 1;
		while (y < game->minimap.mapy + 1)
		{
			draw_64(x, y, game);
			++y;
		}
		++x;
	}
}

void draw_player(t_game *game)
{
	int x = 0;
	int y = 0;
	while (x < game->settings.player_size)
	{
		y = 0;
		while (y < game->settings.player_size)
		{
			my_mlx_pixel_put(game, game->minimap.pos_x + x - game->settings.player_size / 2 + game->minimap.shift_x, game->minimap.pos_y + y - game->settings.player_size / 2 + game->minimap.shift_y, 0x00fae1df);
			++y;
		}
		++x;
	}
}


void draw_ray(t_game *game, float ray_len)
{
	float offset = 0;

	while (offset < ray_len)
	{
		my_mlx_pixel_put(game, game->minimap.pos_x + cos(game->minimap.pa) * game->settings.minimap_scale / 10 * offset + game->minimap.shift_x, game->minimap.pos_y + sin(game->minimap.pa) * game->settings.minimap_scale / 10 * -offset + game->minimap.shift_y, 0x00fae1df);
		offset += 0.2;
	}
}


void display_minimap(t_game *game)
{
	draw_map(game);
	draw_player(game);
	draw_ray(game, game->settings.ray_len);
}