#include "cub3d.h"

void draw_64(int x, int y, t_game *game)
{
	int x2 = 0;
	int y2 = 0;
	if (game->map.map[y][x] == '1')
	{
		while (x2 < 20)
		{
			y2 = 0;
			while (y2 < 20)
			{
				my_mlx_pixel_put_minimap(&game->minimap, x * 20 + x2, y * 20 + y2, 0x00FFFF00);	
				y2++;
			}
			x2++;
		}
	}
	x2 = 0;//draw grid
	y2 = 0;
	while (y2 < 20)
	{
		my_mlx_pixel_put_minimap(&game->minimap, x* 20 + 19, y * 20 + y2, 0x000000FF);
		y2++;
	}
	while (x2 < 20)
	{
		my_mlx_pixel_put_minimap(&game->minimap, x* 20 + x2, y * 20 + 19, 0x000000FF);
		x2++;
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
			y++;
		}
		x++;
	}
}

void draw_player(t_game *game)
{
	int x = 0;
	int y = 0;
	while (x < 6)
	{
		y = 0;
		while (y < 6)
		{
			my_mlx_pixel_put_minimap(&game->minimap, game->minimap.px + 6 + x, game->minimap.py + 6 + y, 0x00FF0000);
			y++;
		}
		x++;
	}
}

void draw_direction(t_game *game)
{
	float offset = 0;

	while (offset < 6)
	{
		my_mlx_pixel_put_minimap(&game->minimap, game->minimap.px + 9 + game->minimap.pdx * offset , game->minimap.py + 9 + game->minimap.pdy * offset, 0x0000F0FF);
		offset += 0.1;
	}
}

void display(t_game *game)
{
	draw_map(game);
	draw_player(game);
	draw_direction(game);
}