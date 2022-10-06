#include "cub3d.h"

int key_event(int keycode, t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	put_floorceil(game);
	if (keycode == 0)
	{
		game->player.direction = game->player.direction + 10;
		if (game->player.direction >= 360)
		{
			game->player.direction -= 360;
		}
		tmp(game);
	}
	if (keycode == 2)
	{
		game->player.direction = game->player.direction - 10;
		if (game->player.direction < 0)
		{
			game->player.direction += 360;
		}
		tmp(game);
	}
	printf("direc %d\n", game->player.direction);
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
		tmp(game);

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
		tmp(game);
	}
	if (keycode == 53)
		tmp_exit();
	return(1);
}