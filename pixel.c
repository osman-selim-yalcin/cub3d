#include "cub3d.h"

void pixelput(t_game *game, double hypo_tmp, double ray_counter)
{
	int a = 0;
	int cnt = 0;

	if (hypo_tmp == 0)
		return ;
	while ((double)a < (150 / hypo_tmp) * (SCREEN_LEN / 2))
		a++;
	if (a % 2 == 1)
		a++;
	int wall = a;
	int start = (SCREEN_LEN - a) / 2;
	int t;

	a = 0;
	if (game->img.which_wall == 1)
		t = game->img.north_y;
	if (game->img.which_wall == 2)
		t = game->img.west_y;
	if (game->img.which_wall == 3)
		t = game->img.south_y;
	if (game->img.which_wall == 4)
		t = game->img.east_y;
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


	if (game->player.ray_abs > game->enemy.start && game->player.ray_abs < game->enemy.finish)
	{
		if (game->enemy.distance < hypo_tmp)
		{
			game->enemy.e_wall_x = game->img.enemy_x * game->enemy.count / game->enemy.width;
			game->enemy.count += (float)game->enemy.width / (float)game->enemy.total_ray;
			a = 0;
			cnt = 0;
			while ((double)a < (150 / game->enemy.distance) * (SCREEN_LEN / 2))
				a++;
			if (a % 2 == 1)
				a++;
			start = (SCREEN_LEN - a) / 2;
			while (cnt < a)
			{
				if ((start + cnt < SCREEN_LEN && start + cnt >= 0) && (SCREEN_WID - 1 - (ray_counter) >= 0 && SCREEN_WID - 1 - (ray_counter) < SCREEN_WID))
				{
					game->enemy.e_wall_y = cnt * game->img.enemy_y / a;
					my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + cnt, take_texture(game, game->enemy.e_wall_x, game->enemy.e_wall_y, 5));
				}
				if (start + cnt >= SCREEN_LEN)
					break;
				cnt++;
			}
		}
	}
}

void put_floorceil(t_game *game, int x, int wall, int start)
{
	int y;

	y = 0;
	while (y < start)
	{
		my_mlx_pixel_put(game, x, y, game->map.ceilling_rgb);
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
