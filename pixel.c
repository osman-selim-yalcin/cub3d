#include "cub3d.h"

void pixelput(t_game *game, float hypo_tmp, float ray_counter)
{
	//hypo 10 = 1080;
	//hypo 20 = 540;
	//hypo 100 = 108;
	// 10 / hyp_len * screen_len
	int	a;
	int cnt = 0;
	// hypo_tmp = 100;
	hypo_tmp = sqrt(hypo_tmp);
	// hypo_tmp = 700;
	a = 0;
	printf("ray %f\n", ray_counter);
	while (a < (sqrt(10) / hypo_tmp) * SCREEN_LEN / 2)
	{
		// if (SCREEN_WID - 1 - ray_counter < 1920 && (SCREEN_LEN / 2) + cnt - 1 < 1080)
		// {
			my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter) * SCREEN_WID / D_FOV, (SCREEN_LEN / 2) + cnt - 1, game->img.color);
			my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter) * SCREEN_WID / D_FOV, (SCREEN_LEN / 2) - cnt + 1, game->img.color);
		// }
		if (!(ray_counter < 0.1))
		{
			my_mlx_pixel_put(game, SCREEN_WID + 1 - ((ray_counter) * SCREEN_WID / D_FOV), (SCREEN_LEN / 2) + cnt - 1, game->img.color);
			my_mlx_pixel_put(game, SCREEN_WID + 1 - ((ray_counter) * SCREEN_WID / D_FOV), (SCREEN_LEN / 2) - cnt + 1, game->img.color);
			my_mlx_pixel_put(game, SCREEN_WID - ((ray_counter) * SCREEN_WID / D_FOV), (SCREEN_LEN / 2) + cnt - 1, game->img.color);
			my_mlx_pixel_put(game, SCREEN_WID - ((ray_counter) * SCREEN_WID / D_FOV), (SCREEN_LEN / 2) - cnt + 1, game->img.color);
		}
		//TEXTURE
		//resize

		// collision
		// walk
		// minimap
		// enemy
		// gun

		// frag granade
		// bumbum
		// phew phew
		// portal
		// game of the year(2092)
		// wolfenstein 3d but 2100 
		++cnt;
		++a;
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