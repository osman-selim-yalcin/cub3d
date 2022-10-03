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
	while (a < (sqrt(10) / hypo_tmp) * SCREEN_LEN / 2)
	{
		my_mlx_pixel_put(game, SCREEN_WID - 1 - ((ray_counter) * SCREEN_WID / D_FOV), (SCREEN_LEN / 2) + cnt - 1, game->img.color);
		my_mlx_pixel_put(game, SCREEN_WID - 1 - ((ray_counter) * SCREEN_WID / D_FOV), (SCREEN_LEN / 2) - cnt + 1, game->img.color);
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