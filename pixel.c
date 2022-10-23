#include "cub3d.h"

void pixelput(t_game *game, double hypo_tmp, double ray_counter)
{
	int a = 0;
	int cnt = 0;

	while ((double)a < (50 / hypo_tmp) * (SCREEN_LEN / 2))
	{
		a++;
	}
	if (a % 2 == 1)
		a++;
	int wall = a;
	int start = (SCREEN_LEN - a) / 2;
	a = 0;
	while (a < wall)
	{
		my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + cnt, game->img.color);
		++cnt;
		a += 1;
	}
}

void put_floorceil(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (x < SCREEN_WID)
	{
		y = 0;
		while (y < SCREEN_LEN / 2)
		{
			my_mlx_pixel_put(game, x, y, game->map.ceilling_rgb);
			++y;
		}
		while (y < SCREEN_LEN)
		{
			my_mlx_pixel_put(game, x, y, game->map.floor_rgb);
			++y;
		}
		x++;
	}
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put_minimap(t_minimap *minimap, int x, int y, int color)
{
	char	*dst;

	dst = minimap->addr + (y * minimap->line_length + x * (minimap->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}