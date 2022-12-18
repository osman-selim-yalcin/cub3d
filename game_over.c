#include "cub3d.h"

int game_over(t_game *game)
{
	int a;
	int b;
	char * dst;
	a = 1;
	while (a < SCREEN_WID)
	{
		b = 1;
		while (b < SCREEN_LEN)
		{
			dst = game->img.dedge_addr + ((game->img.dedge_y * b / SCREEN_LEN) * game->img.dedge_line_length + (game->img.dedge_x * a / SCREEN_WID) * (game->img.dedge_bits_per_pixel / 8));
			my_mlx_pixel_put(game, a, b, *(unsigned int*)dst);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
	return(0);
}