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

int	direction_angle(t_game *game)
{
	if (game->player.direction > 0 && game->player.direction < M_PI / 2)
		return (1);
	if (game->player.direction < M_PI && game->player.direction > M_PI / 2)
		return (2);
	if (game->player.direction < 3 * M_PI / 2 && game->player.direction > M_PI)
		return (3);
	if (game->player.direction < 2 * M_PI && game->player.direction > 3 * M_PI / 2)
		return (4);
	return (5);
}

int key_event(int keycode, t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	put_floorceil(game);
	if (keycode == 0)
	{
		game->player.direction = game->player.direction + 10 * (M_PI / 180);
		if (game->player.direction > 360 * (M_PI / 180))
		{
			game->player.direction -= 2 * M_PI;
		}
		tmp(game);
	}

	if (keycode == 2)
	{
		game->player.direction = game->player.direction - 10 * (M_PI / 180);
		if (game->player.direction < 0)
		{
			game->player.direction += 2 * M_PI;
		}
		tmp(game);
	}

	if (keycode == 13)
	{
		printf("game->player.direction = %f\n", game->player.direction * 180 / M_PI);
		if (direction_angle(game) == 1)
		{
			game->player.pos_x = game->player.pos_x + 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y - 10 * fabs(sin(game->player.direction));
		}
		if (direction_angle(game) == 2)
		{
			game->player.pos_x = game->player.pos_x - 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y - 10 * fabs(sin(game->player.direction));
		}
		if (direction_angle(game) == 3)
		{
			game->player.pos_x = game->player.pos_x - 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y + 10 * fabs(sin(game->player.direction));
		}
		if (direction_angle(game) == 4)
		{
			game->player.pos_x = game->player.pos_x + 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y + 10 * fabs(sin(game->player.direction));
		}
		tmp(game);

	}
	if (keycode == 1)
	{
		printf("game->player.direction = %f\n", game->player.direction * 180 / M_PI);
		if (direction_angle(game) == 1)
		{
			game->player.pos_x = game->player.pos_x - 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y + 10 * fabs(sin(game->player.direction));
		}
		if (direction_angle(game) == 2)
		{
			game->player.pos_x = game->player.pos_x + 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y + 10 * fabs(sin(game->player.direction));
		}
		if (direction_angle(game) == 3)
		{
			game->player.pos_x = game->player.pos_x + 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y - 10 * fabs(sin(game->player.direction));
		}
		if (direction_angle(game) == 4)
		{
			game->player.pos_x = game->player.pos_x - 10 * fabs(cos(game->player.direction));
			game->player.pos_y = game->player.pos_y - 10 * fabs(sin(game->player.direction));
		}
		tmp(game);
	}
	if (keycode == 53)
		tmp_exit();
	return(1);
}

int	ray_angle(t_game *game)
{
	if (game->player.ray_absoulete > 0 && game->player.ray_absoulete < M_PI / 2)
		return (1);
	if (game->player.ray_absoulete < M_PI && game->player.ray_absoulete > M_PI / 2)
		return (2);
	if (game->player.ray_absoulete < 3 * M_PI / 2 && game->player.ray_absoulete > M_PI)
		return (3);
	if (game->player.ray_absoulete < 2 * M_PI && game->player.ray_absoulete > 3 * M_PI / 2)
		return (4);
	return (5);
}

int find_wall_vertical(float hor, float ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (ver < 0 || hor < 0)
	{
		return (2);
	}
	if (ver > 8 || hor > 11)
	{
		return (2);
	}
	if (game->map.map[(int)ver][(int)(hor + 0.5)] == '1' || game->map.map[(int)ver][(int)(hor - 0.5)] == '1')
	{

		return (1);
	}
	return (0);
}

int find_wall_horizontal(float hor, float ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (ver < 0 || hor < 0)
	{
		return (2);
	}

	if (ver > 8 || hor > 11)
	{
		return (2);
	}
	if (game->map.map[(int)(ver + 0.5)][(int)(hor)] == '1' || game->map.map[(int)(ver - 0.5)][(int)(hor)] == '1')
	{
		return (1);
	}
	return (0);
}

void tmp(t_game *game)
{
	game->player.fov = R_FOV;
	float ray_counter = 0;
	float hypo_tmp = 0;
	while (ray_counter * (M_PI / 180) < game->player.fov)
	{
		game->player.ray_absoulete = (game->player.direction - game->player.fov / 2) + (ray_counter * M_PI / 180);
		if (game->player.ray_absoulete < 0)
			game->player.ray_absoulete += 2 * M_PI;
		else if (game->player.ray_absoulete > 360 * M_PI / 180)
			game->player.ray_absoulete -= 2 * M_PI;
		hypo_tmp = 0;
		if (ray_angle(game) == 1)
		{
			game->player.horizontal = 100 - game->player.pos_x % 100;
			game->player.vertical = game->player.pos_y % 100;
			while (1)
			{
				if (find_wall_vertical(game->player.horizontal + game->player.pos_x, game->player.pos_y - tan(game->player.ray_absoulete) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.horizontal + game->player.pos_x, game->player.pos_y - tan(game->player.ray_absoulete) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x00FF0000;
						hypo_tmp = hypot(game->player.horizontal, tan(game->player.ray_absoulete) * game->player.horizontal);
					}
					break ;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x + 1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.pos_y - game->player.vertical, game))
				{
					
					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.vertical))
					{
						game->img.color = 0x000000FF;						
						hypo_tmp = hypot(1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.vertical);
					}
					break ;
				}
				game->player.vertical += 100;
			}
			pixelput(game,hypo_tmp, ray_counter);
		}
		else if(ray_angle(game) == 2)
		{
			game->player.horizontal = game->player.pos_x % 100;
			game->player.vertical = game->player.pos_y % 100;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y - tan(M_PI - game->player.ray_absoulete) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y - tan(M_PI - game->player.ray_absoulete) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x0000FF00;
							hypo_tmp = hypot(game->player.horizontal, tan(M_PI - game->player.ray_absoulete) * game->player.horizontal);
					}
					break ;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x - 1 / tan(M_PI - game->player.ray_absoulete) * game->player.vertical, game->player.pos_y - game->player.vertical, game))
				{
					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(M_PI - game->player.ray_absoulete) * game->player.vertical, game->player.vertical))
					{
						game->img.color = 0x000000FF;
						hypo_tmp = hypot(1 / tan(M_PI - game->player.ray_absoulete) * game->player.vertical, game->player.vertical);
					}
					break ;
				}
				game->player.vertical += 100;
			}
			pixelput(game,hypo_tmp, ray_counter);	
		}
		else if(ray_angle(game) == 3)
		{
			game->player.horizontal = game->player.pos_x % 100;
			game->player.vertical = 100 - game->player.pos_y % 100;
			game->player.ray_absoulete -= M_PI;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y + tan(game->player.ray_absoulete) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y + tan(game->player.ray_absoulete) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x0000FF00;
						hypo_tmp = hypot(game->player.horizontal, tan(game->player.ray_absoulete) * game->player.horizontal);
					}
					break ;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x - 1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.pos_y + game->player.vertical, game))
				{
					
					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.vertical))
					{
						game->img.color = 0x00FFFF00;
						hypo_tmp = hypot(1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.vertical);
					}
					break ;
				}
				game->player.vertical += 100;
			}
			pixelput(game,hypo_tmp, ray_counter);
		}
		else if(ray_angle(game) == 4)
		{
			game->player.horizontal = 100 - game->player.pos_x % 100;
			game->player.vertical = 100 - game->player.pos_y % 100;
			game->player.ray_absoulete = 2 * M_PI - game->player.ray_absoulete;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x + game->player.horizontal, game->player.pos_y + tan(game->player.ray_absoulete) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x + game->player.horizontal, game->player.pos_y + tan(game->player.ray_absoulete) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x00FF0000;
						hypo_tmp = hypot(game->player.horizontal, tan(game->player.ray_absoulete) * game->player.horizontal);
					}
					break ;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x + 1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.pos_y + game->player.vertical, game))
				{
					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.vertical))
					{
						game->img.color = 0x00FFFF00;
						hypo_tmp = hypot(1 / tan(game->player.ray_absoulete) * game->player.vertical, game->player.vertical);
					}
					break ;
				}
				game->player.vertical += 100;
			}
			pixelput(game,hypo_tmp, ray_counter);
		}
		ray_counter += 0.1;
	}
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
}

int main(int ac, char **av)
{
	t_game game;

	get_value(&game, av);
	if (check_map(&game, ac)) //error_managment;
		return (1);
	
	game.libx.mlx = mlx_init();
	game.libx.win = mlx_new_window(game.libx.mlx, SCREEN_WID, SCREEN_LEN, "cub3d");

	game.img.img = mlx_new_image(game.libx.mlx, SCREEN_WID, SCREEN_LEN);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
	
	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return(0);
}