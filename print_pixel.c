#include "cub3d.h"

void pixelput(t_game *game, double hypo, double ray_counter)
{
	int a;
	int cnt;
	int wall;
	int start;
	int t;

	a = 0;
	cnt = 0;
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
	if (start < 0)
	{
		cnt = -start;
		a = -start;
	}
	while (a < wall)
	{
		if ((start + cnt < SCREEN_LEN && start + cnt >= 0) && (SCREEN_WID - 1 - (ray_counter) >= 0 && SCREEN_WID - 1 - (ray_counter) < SCREEN_WID))
		{
			game->img.wall_y = a * t / wall;
			my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + cnt, take_texture(game, game->img.wall_x, game->img.wall_y, game->img.which_wall));
		}
		if (start + cnt >= SCREEN_LEN)
			break;
		++cnt;
		++a;
	}
	put_floorceil(game, SCREEN_WID - 1 - (ray_counter), wall, start);
	enemy_print(game, ray_counter, hypo);
}

void put_floorceil(t_game *game, int x, int wall, int start)
{
	int y;

	y = 0;
	game->img.ceil_index_x = game->img.ceilx * game->player.ray_abs / 360;	
	while (y < start)
	{
		game->img.ceil_index_y = game->img.ceily *  y / (SCREEN_LEN);
		my_mlx_pixel_put(game, x, y, take_texture(game, game->img.ceil_index_x, game->img.ceil_index_y, 6));
		y++;
	}
	while (y + wall < SCREEN_LEN)
	{
		my_mlx_pixel_put(game, x, y + wall, game->map.floor_rgb);
		y++;
	}
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
