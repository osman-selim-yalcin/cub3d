#include "cub3d.h"



void print_frame(t_game *game, int action)
{
	static int trans = 255;
	int a;
	int b;
	static int color = 120;

	a = 0;
	if (action == 1 && trans > 180)
	{
		trans -= 20;
		game->player.hp_count = game->level.regen;
		game->player.hp--;
	}
	if (!action && trans <= 235)
	{
		trans += 20;
		game->player.hp++;
	}
	while (a < SCREEN_WID)
	{
		b = 0;
		while (b < SCREEN_LEN)
		{
			my_mlx_pixel_put_frame(game, a, b,  create_trgb(trans, color, 0, 0));
			b++;
		}
		a++;
	}
	a = SCREEN_WID / 2 - 10;
	b = SCREEN_LEN / 2 - 10;
	int x_move = SCREEN_WID / 50;
	int y_move = - SCREEN_LEN / 10;
	while (a < SCREEN_WID / 2 + 10)
	{
		if (!(a < SCREEN_WID / 2 + 3 && a > SCREEN_WID / 2 - 3))
			my_mlx_pixel_put_frame(game, a + x_move, SCREEN_LEN / 2 + y_move,  create_trgb(0, 200, 100, 100));
		a++;
	}
	while (b < SCREEN_LEN / 2 + 10)
	{
		if (!(b < SCREEN_LEN / 2 + 3 && b > SCREEN_LEN / 2 - 3))
			my_mlx_pixel_put_frame(game, SCREEN_WID / 2 + x_move, b + y_move,  create_trgb(0, 200, 100, 100));
		b++;
	}
	
	
}

void	my_mlx_pixel_put_frame(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (!((y < SCREEN_LEN && y >= 0) && (x >= 0 && x < SCREEN_WID)))
	{
		return ;
	}
	dst = game->img.addr_f + (y * game->img.line_length_f + x * (game->img.bits_per_pixel_f / 8));
	*(unsigned int*)dst = color;
}