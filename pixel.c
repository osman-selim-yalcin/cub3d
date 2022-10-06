#include "cub3d.h"

void pixelput(t_game *game, double hypo_tmp, double ray_counter)
{
	int a = 0;
	int cnt = 0;

	while ((double)a < ((15 / hypo_tmp) * SCREEN_LEN / 2) -  0.5)
		a++;
	printf("a %d\n", a);
	int wall = a;
	printf("duvar uzunluk %d, while %lf\n", wall, (10 / hypo_tmp) * SCREEN_LEN / 2);
	int start = (SCREEN_LEN - a) / 2;
	a = 0;
	// printf("ray %f\n", ray_counter);
	// printf("-------------------------------\n");
	// if (ray_counter > 1800)
	// {
	// 	printf("ray %f\n", game->player.ray_absoulete);
	// 	printf("x: %f, y: %d, color: %x\n", ray_counter, start + cnt, game->img.color);
	// }
	while (a < wall)
	{
		
		// if (ray_counter == 1840)
		// {
		// 	printf("screen %f, start %d\n",  SCREEN_WID - 1 - (ray_counter), start + cnt);
		// }
		my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + cnt, game->img.color);
		//TEXTURE
		//resize

		// collision
		// walk
		// minimap
		// enemy
		// gun
		++cnt;
		a += 1;
	}
	if (ray_counter > 1600)
	{
		printf("hypo tmp %f, ray counter %f,  cnt %d\n", hypo_tmp, ray_counter ,cnt);
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