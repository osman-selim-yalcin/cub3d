#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

void tmp(t_game *game)
{
	float ray_counter = 0;
	float hypo_tmp = 0;
	while (ray_counter < game->player.fov)
	{
		hypo_tmp = 0;
		game->player.ray_absoulete = (game->player.direction - game->player.fov / 2) + (ray_counter);
		if (game->player.ray_absoulete < 0)
			game->player.ray_absoulete += 360;
		else if (game->player.ray_absoulete >= 360)
			game->player.ray_absoulete -= 360;
		if (ray_angle(game) == 1)
		{
			game->player.horizontal = 100 - game->player.pos_x % 100;
			game->player.vertical = game->player.pos_y % 100;
			while (1)
			{
				if (find_wall_vertical(game->player.horizontal + game->player.pos_x, game->player.pos_y - tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.horizontal + game->player.pos_x, game->player.pos_y - tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x00FF0000;
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
						game->img.color = 0x000000FF;
						hypo_tmp = hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete) - deg_to_rad(game->player.direction)));
			pixelput(game, hypo_tmp, ray_counter);
		}
		else if (ray_angle(game) == 2)
		{
			game->player.horizontal = game->player.pos_x % 100;
			game->player.vertical = game->player.pos_y % 100;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y - tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y - tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x0000FF00;
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
						game->img.color = 0x000000FF;
						hypo_tmp = hypot(1 / tan(M_PI - deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete) - deg_to_rad(game->player.direction)));
			pixelput(game, hypo_tmp, ray_counter);
		}
		else if (ray_angle(game) == 3)
		{
			game->player.horizontal = game->player.pos_x % 100;
			game->player.vertical = 100 - game->player.pos_y % 100;
			game->player.ray_absoulete -= 180;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y + tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x - game->player.horizontal, game->player.pos_y + tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x0000FF00;
						hypo_tmp = hypot(game->player.horizontal, tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal);
					}
					break;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x - 1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.pos_y + game->player.vertical, game))
				{

					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical))
					{
						game->img.color = 0x00FFFF00;
						hypo_tmp = hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete + 180 - game->player.direction)));
			pixelput(game, hypo_tmp, ray_counter);
		}
		else if (ray_angle(game) == 4)
		{
			game->player.horizontal = 100 - game->player.pos_x % 100;
			game->player.vertical = 100 - game->player.pos_y % 100;
			game->player.ray_absoulete = 360 - game->player.ray_absoulete;
			while (1)
			{
				if (find_wall_vertical(game->player.pos_x + game->player.horizontal, game->player.pos_y + tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) > 0)
				{
					if (find_wall_vertical(game->player.pos_x + game->player.horizontal, game->player.pos_y + tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal, game) == 1)
					{
						game->img.color = 0x00FF0000;
						hypo_tmp = hypot(game->player.horizontal, tan(deg_to_rad(game->player.ray_absoulete)) * game->player.horizontal);
					}
					break;
				}
				game->player.horizontal += 100;
			}
			while (1)
			{
				if (find_wall_horizontal(game->player.pos_x + 1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.pos_y + game->player.vertical, game))
				{
					if (hypo_tmp == 0 || hypo_tmp > hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical))
					{
						game->img.color = 0x00FFFF00;
						hypo_tmp = hypot(1 / tan(deg_to_rad(game->player.ray_absoulete)) * game->player.vertical, game->player.vertical);
					}
					break;
				}
				game->player.vertical += 100;
			}
			hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(fabs(game->player.ray_absoulete - 360) - game->player.direction)));
			// hypo_tmp = hypo_tmp * fabs(cos(deg_to_rad(game->player.ray_absoulete - game->player.direction)));
			// printf("tmp: %f\n", hypo_tmp);
			pixelput(game, hypo_tmp, ray_counter);
		}
		ray_counter += 0.1;
	}
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
}

int main(int ac, char **av)
{
	t_game game;

	game.player.fov = D_FOV;
	get_value(&game, av);
	if (check_map(&game, ac)) // error_managment;
		return (1);

	game.libx.mlx = mlx_init();
	game.libx.win = mlx_new_window(game.libx.mlx, SCREEN_WID, SCREEN_LEN, "cub3d");

	game.img.img = mlx_new_image(game.libx.mlx, SCREEN_WID, SCREEN_LEN);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
	// printf("%f\n", deg_to_rad(80.1));
	// printf("%f\n", deg_to_rad(80.2));
	// printf("%f\n", deg_to_rad(80.3));
	// printf("%f\n", deg_to_rad(80.4));
	// printf("%f\n", deg_to_rad(80.5));
	// printf("%f\n", deg_to_rad(80.6));
	// printf("%f\n", deg_to_rad(80.7));
	// printf("%f\n", deg_to_rad(80.8));
	// printf("%f\n", deg_to_rad(80.9));
	// put_floorceil(&game);
	// tmp(&game);
	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}