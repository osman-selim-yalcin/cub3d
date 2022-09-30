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

void put_pixels(t_game *game)
{
	int x = 0;
	int y = 0;
	while (y < 1080)
	{
		if (y < game->libx.bottom_start)
		{
			x = 0;
			while (x < 1920)
			{
				my_mlx_pixel_put(game, x, y, game->map.ceilling_rgb);
				x++;
			}
		}
		else if (y >= game->libx.bottom_start && y <= game->libx.top_start)
		{
			x = 0;
			while (x < 1920)
			{
				my_mlx_pixel_put(game, x, y, 0x00aacfcf);
				x++;
			}
		}
		else if (y > game->libx.top_start)
		{
			x = 0;
			while (x < 1920)
			{
				my_mlx_pixel_put(game, x, y, game->map.floor_rgb);
				x++;
			}
		}
		y++;
	}
}

int key_event(int keycode, t_game *game)
{
	(void)game;
	mlx_clear_window(game->libx.mlx, game->libx.win);
	game->img.addr = mlx_get_data_addr(game->img.big_img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	if (keycode == 53)
		tmp_exit();
	if (keycode == 13)
	{
		game->libx.bottom_start -= 10;
		game->libx.top_start += 10;
		put_pixels(game);
	}
	else if (keycode == 1)
	{
		game->libx.bottom_start += 10;
		game->libx.top_start -= 10;
		put_pixels(game);
	}
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.big_img, 0, 0);
	return(1);
}

int main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
	{
		printf("invalid arguments\n");
		exit(1);
	}
	get_value(&game, av);
	if (check_map(&game)) //error_managment;
	{
		printf("map error\n");
		exit(1);
	}
	game.libx.mlx = mlx_init();
	game.libx.win = mlx_new_window(game.libx.mlx, 1920, 1080, "cub3d");

	game.libx.bottom_start = 300;
	game.libx.top_start = 800;

	game.img.big_img = mlx_new_image(game.libx.mlx, 1920, 1080);
	game.img.addr = mlx_get_data_addr(game.img.big_img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
	put_pixels(&game);
	mlx_put_image_to_window(game.libx.mlx, game.libx.win, game.img.big_img, 0, 0);

	//game.img.north_img = mlx_xpm_file_to_image(game.libx.mlx, game.map.north_texture, &game.img.north_width, &game.img.north_height);

	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return(0);
}