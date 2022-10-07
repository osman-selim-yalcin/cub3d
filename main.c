#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

void tmp(t_game *game)
{
	double ray_counter = 0;
	double hypo_tmp = 0;
	while (ray_counter < SCREEN_WID)
	{
		hypo_tmp = 0;
		game->player.ray_absoulete = (game->player.direction - game->player.fov / 2) + (ray_counter / SCREEN_WID * D_FOV);
		if (game->player.ray_absoulete < 0)
			game->player.ray_absoulete += 360;
		else if (game->player.ray_absoulete >= 360)
			game->player.ray_absoulete -= 360;
		if (ray_angle(game) == 1)
		{
			game->player.horizontal = 100 - game->player.pos_x % 100;
			game->player.vertical = game->player.pos_y % 100;
			if (game->player.vertical == 0)
				game->player.vertical = 100;
			while (1)
			{
				if (find_wall_vertical(game->player.horizontal + game->player.pos_x, game->player.pos_y - tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.horizontal + game->player.pos_x, game->player.pos_y - tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) == 1)
					{
						//game->img.color = 0x00FF0000;
						game->img.color_wall = 1;
						hypo_tmp = hypot(game->player.horizontal, tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal);
					}
					break;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x + 1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.pos_y - game->player.vertical, game))
				{

					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical))
					{
						if (!take_approximate(hypo_tmp, hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical)))
						{
							game->img.color = 0x000000FF;
							game->img.color_wall = 0;
						}
						else
							printf("hypo_tmp %f, %f\n", hypo_tmp, hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical));
						hypo_tmp = hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			if (game->img.color_wall == 1)
			{
				game->img.color = 0x00FF0000;
			}	
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete) - deg_to_rad(game->player.direction)));
			pixelput(game, hypo_tmp, ray_counter);
		}
		else if (ray_angle(game) == 2)
		{
			game->player.horizontal = game->player.pos_x % 100;
			game->player.vertical = game->player.pos_y % 100;
			if (game->player.vertical == 0)
				game->player.vertical = 100;
			if (game->player.horizontal == 0)
			{
				game->player.horizontal = 100;
			}
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y - tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y - tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) == 1)
					{
						game->img.color_wall = 1;
						//game->img.color = 0x0000FF00;
						hypo_tmp = hypot(game->player.horizontal, tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal);
					}
					break;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x - 1 / tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.pos_y - game->player.vertical, game))
				{
					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical))
					{
						if (!take_approximate(hypo_tmp, hypot(1 / tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical)))
						{
							game->img.color_wall = 0;
							game->img.color = 0x000000FF;
						}
						else
							printf("köşedeyim %f, %f", hypo_tmp, hypot(1 / tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical));
						hypo_tmp = hypot(1 / tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			if (game->img.color_wall == 1)
			{
				game->img.color = 0x0000FF00;
			}
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete) - deg_to_rad(game->player.direction)));
			pixelput(game, hypo_tmp, ray_counter);
		}
		else if (ray_angle(game) == 3)
		{
			game->player.horizontal = game->player.pos_x % 100;
			game->player.vertical = 100 - game->player.pos_y % 100;
			if (game->player.horizontal == 0)
				game->player.horizontal = 100;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y + tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y + tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.horizontal, game) == 1)
					{
						// game->img.color = 0x0000FF00;
						game->img.color_wall = 1;
						hypo_tmp = hypot(game->player.horizontal, tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.horizontal);
					}
					break;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x - 1 / tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.vertical, game->player.pos_y + game->player.vertical, game))
				{

					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.vertical, game->player.vertical))
					{
						if (!take_approximate(hypo_tmp, hypot(1 / tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.vertical, game->player.vertical)))
						{
							game->img.color_wall = 0;
							game->img.color = 0x00FFFF00;
						}
						else
						{
							printf("abs %lf raycounter %f köşedeyim %f,  %f\n", game->player.ray_absoulete,ray_counter,hypo_tmp, hypot(1 / tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.vertical, game->player.vertical));
						}
						hypo_tmp = hypot(1 / tan(deg_to_rad(game->player.ray_absoulete - 180)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			if (game->img.color_wall == 1)
			{
				game->img.color = 0x0000FF00;
			}
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete - game->player.direction)));
			pixelput(game, hypo_tmp, ray_counter);
		}
		else if (ray_angle(game) == 4)
		{
			game->player.horizontal = 100 - game->player.pos_x % 100;
			game->player.vertical = 100 - game->player.pos_y % 100;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x + game->player.horizontal, game->player.pos_y + tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x + game->player.horizontal, game->player.pos_y + tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.horizontal, game) == 1)
					{
						game->img.color_wall= 1;
						// game->img.color = 0x00FF0000;
						hypo_tmp = hypot(game->player.horizontal, tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.horizontal);
					}
					break;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{

				if (find_wall_horizontal(game->player.pos_x + 1 / tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.vertical, game->player.pos_y + game->player.vertical, game))
				{
					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.vertical, game->player.vertical))
					{
						if (!take_approximate(hypo_tmp, hypot(1 / tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.vertical, game->player.vertical)))
						{
							game->img.color_wall = 0;
							game->img.color = 0x00FFFFFF;
						}
						else
						{
							printf("raycounter %f köşedeyim %f,  %f\n", ray_counter,hypo_tmp, hypot(1 / tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.vertical, game->player.vertical));
						}
						hypo_tmp = hypot(1 / tan(deg_to_rad(360 - game->player.ray_absoulete)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			if (game->img.color_wall == 1)
			{
				game->img.color = 0x00FF0000;
			}
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete - game->player.direction)));
			pixelput(game, hypo_tmp, ray_counter);
		}
		ray_counter += 1;
	}
	display(game);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
}

int main(int ac, char **av)
{
	t_game game;

	game.player.fov = D_FOV;
	get_value(&game, av);
	if (check_map(&game, ac)) // error_managment;
		return (1);
	game.minimap.px = game.player.pos_x / 100 * 16;
	game.minimap.py = game.player.pos_y / 100 * 16;
	printf("%d\n", game.player.direction);
	game.minimap.pa = deg_to_rad(game.player.direction);
	game.minimap.pdx = cos(game.minimap.pa) * 5;
	game.minimap.pdy = sin(game.minimap.pa) * 5;
	game.minimap.mapx = game.map.width;
	game.minimap.mapy = game.map.length;
	game.minimap.mapsize = game.map.width * game.map.length;
	//color initli olsun
	game.libx.mlx = mlx_init();
	game.libx.win = mlx_new_window(game.libx.mlx, SCREEN_WID, SCREEN_LEN, "cub3d");

	game.img.img = mlx_new_image(game.libx.mlx, SCREEN_WID, SCREEN_LEN);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);

	game.minimap.img = mlx_new_image(game.libx.mlx, SCREEN_WID, SCREEN_LEN);
	game.minimap.addr = mlx_get_data_addr(game.img.img, &game.minimap.bits_per_pixel, &game.minimap.line_length, &game.minimap.endian);

	put_floorceil(&game);
	tmp(&game);
	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}