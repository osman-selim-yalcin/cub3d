#include "cub3d.h"

void pixelput(t_game *game, float hypo_tmp, float ray_counter)
{
	//hypo 10 = 1080;
	//hypo 20 = 540;
	//hypo 100 = 108;
	// 10 / hyp_len * screen_len
	int	a;
	int b;
	int cnt = 0;
	// hypo_tmp = 100;
	hypo_tmp = sqrt(hypo_tmp);
	// hypo_tmp = 700;
	a = 0;
	while (a < (sqrt(10) / hypo_tmp) * SCREEN_LEN / 2)
	{
		// my_mlx_pixel_put(game, SCREEN_WID - (ray_counter * SCREEN_WID / D_FOV) - 1, a, 0x0FF00000);
		b = 0;
		while (b < SCREEN_WID / D_FOV)
		{
			my_mlx_pixel_put(game, SCREEN_WID - ((ray_counter) * SCREEN_WID / D_FOV) + b, (SCREEN_LEN / 2) + cnt - 1, 0x0FF00000);
			my_mlx_pixel_put(game, SCREEN_WID - ((ray_counter) * SCREEN_WID / D_FOV) + b, (SCREEN_LEN / 2) - cnt + 1, 0x0FF00000);
			b++;
		}
		++cnt;
		++a;
	}

}