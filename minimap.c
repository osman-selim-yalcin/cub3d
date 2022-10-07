#include "cub3d.h"

void draw_64(int x, int y, t_game *game)
{
	int x2 = 0;
	int y2 = 0;
	if (game->map.map[y][x] == '1')
	{
		while (x2 < 16)
		{
			y2 = 0;
			while (y2 < 16)
			{
				my_mlx_pixel_put_minimap(&game->minimap, x * 16 + x2, y * 16 + y2, 0x00FFFF00);	
				y2++;
			}
			x2++;
		}
	}
	x2 = 0;//draw grid
	y2 = 0;
	while (y2 < 16)
	{
		my_mlx_pixel_put_minimap(&game->minimap, x* 16 + 15, y * 16 + y2, 0x000000FF);
		y2++;
	}
	while (x2 < 16)
	{
		my_mlx_pixel_put_minimap(&game->minimap, x* 16 + x2, y * 16 + 15, 0x000000FF);
		x2++;
	}
}

void draw_map(t_game *game)
{
	int x = 0;
	int y = 0;
	while (x < game->minimap.mapx)
	{
		y = 0;
		while (y < game->minimap.mapy)
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
	while (x < 8)
	{
		y = 0;
		while (y < 8)
		{
			my_mlx_pixel_put_minimap(&game->minimap, game->minimap.px + x, game->minimap.py + y, 0x00FF0000);
			y++;
		}
		x++;
	}
}

void draw_ray3d(t_game *game)
{
	game->minimap.ra = game->minimap.pa;
	int r = 0;
	while (r < 1) //check_horizon
	{
		float aTan = -1/tan(game->minimap.ra);
		if (game->minimap.ra > M_PI)
		{
			game->minimap.ry = (((int)game->minimap.py >> 6) << 6) - 0.0001;
			game->minimap.rx = (game->minimap.py - game->minimap.ry) * aTan + game->minimap.px;
			game->minimap.yo = -64;
			game->minimap.xo = -game->minimap.yo * aTan;
		}
		if (game->minimap.ra < M_PI)
		{
			game->minimap.ry = (((int)game->minimap.py >> 6) << 6) + 64;
			game->minimap.rx = (game->minimap.py - game->minimap.ry) * aTan + game->minimap.px;
			game->minimap.yo = 64;
			game->minimap.xo = -game->minimap.yo * aTan;
		}
		if (game->minimap.ra == 0 || game->minimap.ra == M_PI)
		{
			game->minimap.rx = game->minimap.px;
			game->minimap.ry = game->minimap.py;
			game->minimap.dof = 8;
		}
		while (game->minimap.dof < 8)
		{
			game->minimap.mx = (int)(game->minimap.rx) >> 6;
			game->minimap.my = (int)(game->minimap.ry) >> 6;
			game->minimap.mp = game->minimap.my * game->minimap.mapx +game->minimap.mx;
			if (game->minimap.mp > 0 && game->minimap.mp < game->minimap.mapx * game->minimap.mapy && game->map.map[game->minimap.my][game->minimap.mx] == '1')
			{
				game->minimap.dof = 8;
			}
			else
			{
				game->minimap.rx += game->minimap.xo;
				game->minimap.ry += game->minimap.yo;
				game->minimap.dof += 1;
			}
		}
		r++;
	}
}

void draw_pipi(t_game *game)
{
	float offset = 0;

	while (offset < 6)
	{
		my_mlx_pixel_put_minimap(&game->minimap, game->minimap.px + 4 + game->minimap.pdx * offset , game->minimap.py + 4 + game->minimap.pdy * offset, 0x0000F0FF);
		offset += 0.1;
	}
	
}

void display(t_game *game)
{
	draw_map(game);
	draw_player(game);
	draw_ray3d(game);
	draw_pipi(game);
}