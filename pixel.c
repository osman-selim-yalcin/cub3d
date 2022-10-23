#include "cub3d.h"

void pixelput(t_game *game, double hypo_tmp, double ray_counter)
{
	(void)game;
	(void)hypo_tmp;
	(void)ray_counter;
	printf("pixel put\n");
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
