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
				if (x2 < game->settings.minimap_scale / 20 || x2 >= game->settings.minimap_scale - (game->settings.minimap_scale / 20) || \
					y2 < game->settings.minimap_scale / 20 || y2 >= game->settings.minimap_scale - (game->settings.minimap_scale / 20))//grid frame
					my_mlx_pixel_put(game, x * game->settings.minimap_scale + x2, y * game->settings.minimap_scale + y2, 0x00FF6B00);
				else//wall
					my_mlx_pixel_put(game, x * game->settings.minimap_scale + x2, y * game->settings.minimap_scale + y2, 0x00FFFF00);
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
				my_mlx_pixel_put(game, x * game->settings.minimap_scale + x2, y * game->settings.minimap_scale + y2, 0x00000000);
				y2++;
			}
			x2++;
		}
	}
}

void draw_map(t_game *game)
{
	int x = 1;
	int y = 1;
	while (x < game->minimap.mapx - 1)
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
			// my_mlx_pixel_put(game, 50 + x, 50 + y, 0x00FF0000);
			printf("x: %f, y: %f\n", game->minimap.pos_x + x, game->minimap.pos_y + y);
			my_mlx_pixel_put(game, game->minimap.pos_x + game->settings.minimap_scale / 4 + x, game->minimap.pos_y + game->settings.minimap_scale / 4 + y, 0x00FF0000);
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
		my_mlx_pixel_put(game, game->minimap.pos_x + game->settings.minimap_scale / 4 + game->settings.player_size / 2 + game->minimap.step_offset_x * offset, game->minimap.pos_y + game->settings.minimap_scale / 4 + game->settings.player_size / 2 + game->minimap.step_offset_y * offset, 0x00FF539E);
		offset += 0.2;
	}
}

void display(t_game *game)
{
	draw_map(game);
	draw_player(game);
	draw_ray(game, game->settings.ray_len);
}