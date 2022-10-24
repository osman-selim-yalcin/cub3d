#include "cub3d.h"

int key_event(int keycode, t_game *game)
{
	printf("key %d\n", keycode);
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->minimap.addr = mlx_get_data_addr(game->img.img, &game->minimap.bits_per_pixel, &game->minimap.line_length, &game->minimap.endian);
	put_floorceil(game);
	if (keycode == 123) // left
	{
		game->player.direction += 5;
		if (game->player.direction >= 360)
			game->player.direction -= 360;
		game->minimap.pa -= 2 * M_PI / 36;
		if (game->minimap.pa < 0)
		{
			game->minimap.pa += 2 * M_PI;
		}
		game->minimap.pdx = cos(game->minimap.pa) * 2;
		game->minimap.pdy = sin(game->minimap.pa) * 2;
	}
	if (keycode == 124) // right
	{
		game->player.direction -= 5;
		if (game->player.direction < 0)
			game->player.direction += 360;
		game->minimap.pa += 2 * M_PI / 36;
		if (game->minimap.pa > 2 * M_PI)
		{
			game->minimap.pa -= 2 * M_PI;
		}
		game->minimap.pdx = cos(game->minimap.pa) * 2;
		game->minimap.pdy = sin(game->minimap.pa) * 2;
	}
	if (keycode == 0)
	{
		game->player.direction += 90;
		if (game->player.direction >= 360)
			game->player.direction -= 360;
		if (direction_angle(game) == 1)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 2)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 3)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 4)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		game->player.direction -= 90;
		if (game->player.direction < 0)
			game->player.direction += 360;
	}
	if (keycode == 2)
	{
		game->player.direction -= 90;
		if (game->player.direction < 0)
			game->player.direction += 360;
		if (direction_angle(game) == 1)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 2)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 3)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 4)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		game->player.direction += 90;
		if (game->player.direction >= 360)
			game->player.direction -= 360;
	}
	if (keycode == 13)
	{
		if (direction_angle(game) == 1)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 2)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 3)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 4)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		game->minimap.px += game->minimap.pdx;
		game->minimap.py += game->minimap.pdy;
	}
	if (keycode == 1)
	{
		if (direction_angle(game) == 1)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 2)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y + round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 3)
		{
			game->player.pos_x = game->player.pos_x + round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		if (direction_angle(game) == 4)
		{
			game->player.pos_x = game->player.pos_x - round_double(10 * fabs(cos(deg_to_rad(game->player.direction))));
			game->player.pos_y = game->player.pos_y - round_double(10 * fabs(sin(deg_to_rad(game->player.direction))));
		}
		game->minimap.px -= game->minimap.pdx;
		game->minimap.py -= game->minimap.pdy;
	}
	if (keycode == 53)
		tmp_exit();
	start(game);
	return(1);
}