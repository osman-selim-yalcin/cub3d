#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_event(int keycode, t_game *game)
{
	(void)game;
	if (keycode == 53)
		tmp_exit();
	return(1);
}

int	ray_angle(t_game *game)
{
	if (game->player.ray_absoulete > 0 && game->player.ray_absoulete < M_PI / 2)
		return (1);
	if (game->player.ray_absoulete > M_PI && game->player.ray_absoulete > M_PI / 2)
		return (2);
	if (game->player.ray_absoulete < 3 * M_PI / 2 && game->player.ray_absoulete > M_PI)
		return (3);
	if (game->player.ray_absoulete < 2 * M_PI && game->player.ray_absoulete > 3 * M_PI / 2)
		return (4);
	return (5);
}

int find_wall(float hor, float ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (game->map.map[(int)ver][(int)(hor + 0.5)] == '1' || game->map.map[(int)ver][(int)(hor -1 0.5)] == '1')
	{
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_game game;

	get_value(&game, av);
	if (check_map(&game, ac)) //error_managment;
		return (1);
	game.libx.mlx = mlx_init();
	game.libx.win = mlx_new_window(game.libx.mlx, 1920, 1080, "cub3d");

	game.img.img = mlx_new_image(game.libx.mlx, 1920, 1080);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
	game.player.fov = 2 * M_PI / 3;
	game.player.pos_x = 650;
	game.player.pos_y = 350;
	which_area(&game);
	int left = 50;
	int right = 50;
	int i = 0;
	int j = 0;
	float ray_counter = 0;

	while (ray_counter < game.player.fov)
	{
		game.player.ray_absoulete = (game.player.direction - game.player.fov / 2) + ray_counter;
		if (ray_angle(&game))
		{
			game.player.horizontal = 100 - game.player.pos_x % 100;
			game.player.vertical = game.player.pos_y % 100;
			while (1)
			{
				//hypo
				if (find_wall_vertical(game.player.horizontal + game.player.pos_x + i, game.player.pos_y - tan(game.player.ray_absoulete) * game.player.horizontal, game))
				{
					//find hipo
				}
				i+= 100;
				if (find_wall_horizontal())
				{
					//find hipo
					//if hypo not equal 0 and less then hypo
					//if hypo 0 put
				}
				// if hypo not 0 break
			}
		}
		else if(ray_angle(&game))
		{
			game.player.horizontal = game.player.pos_x % 100;
			game.player.vertical = game.player.pos_y % 100;
		}
		else if(ray_angle(&game))
		{
			game.player.horizontal = game.player.pos_x % 100;
			game.player.vertical = 100 - game.player.pos_y % 100;
		}
		else if(ray_angle(&game))
		{
			game.player.horizontal = 100 - game.player.pos_x % 100;
			game.player.vertical = 100 - game.player.pos_y % 100;
		}
	}
	
	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return(0);
}