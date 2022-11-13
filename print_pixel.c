#include "cub3d.h"

void pixelput(t_game *game, double hypo, double ray_counter)
{
	int a;
	int wall;
	int start;
	int t;
	int real_wall;

	a = 0;
	real_wall = 0;
	if (hypo == 0)
		return ;
	while ((double)a < (150 / hypo) * (SCREEN_LEN / 2))
		a++;
	if (a % 2 == 1)
		a++;
	wall = a;
	start = (SCREEN_LEN - a) / 2;

	a = 0;
	if (game->img.which_wall == 1)
		t = game->img.north_y;
	if (game->img.which_wall == 2)
		t = game->img.west_y;
	if (game->img.which_wall == 3)
		t = game->img.south_y;
	if (game->img.which_wall == 4)
		t = game->img.east_y;
	if (game->img.which_wall == 7)
		t = game->img.door_y;
	start += game->mouse_horizontal;
	if (start < 0)
		a = -start;
	while (a < wall)
	{
		game->img.wall_y = a * t / wall;
		my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + a, take_texture(game, game->img.wall_x, game->img.wall_y, game->img.which_wall));
		if (start + a >= SCREEN_LEN)
			break;
		++a;
		++real_wall;
	}
	put_floorceil(game, SCREEN_WID - 1 - (ray_counter), real_wall, start);
}

void put_floorceil(t_game *game, int x, int real_wall, int start)
{
	int y;

	y = 0;
	while (y < start)
	{
		if (y >= SCREEN_LEN)
			break;
		my_mlx_pixel_put(game, x, y, game->map.ceilling_rgb);
		y++;
	}
	while (y + real_wall < SCREEN_LEN)
	{
		my_mlx_pixel_put(game, x, y + real_wall, game->map.floor_rgb);
		y++;
	}
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (!((y < SCREEN_LEN && y >= 0) && (x >= 0 && x < SCREEN_WID)))
	{
		return ;
	}
	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
