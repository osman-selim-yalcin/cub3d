#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img->addr + (y * game->img->line_length + x * (game->img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int mouse_hook(int mousecode, t_game *game)
{
	printf("lala\n");
	printf("%d\n", game->map->gnl_count);
	printf("%p\n", game->libx->mlx);
	mlx_clear_window(game->libx->mlx, game->libx->win);
	if (mousecode == 1)
	{
		printf("mousecode: %d\n", mousecode);
		my_mlx_pixel_put(game, 100, 100, 0x00FF0000);
	}
	if (mousecode == 2)
	{
		printf("mousecode: %d\n", mousecode);
		my_mlx_pixel_put(game, 100, 200, 0x000000FF);
	}
	mlx_put_image_to_window(game->libx->mlx, game->libx->win, game->img->big_img, 0, 0);
	return(1);
}

int key_event(int keycode, t_game *game)
{
	(void)game;
	if (keycode == 53)
		tmp_exit();
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
	game.libx = malloc(sizeof(t_libx));
	game.img = malloc(sizeof(t_img));
	game.map = malloc(sizeof(t_map));
	game.player = malloc(sizeof(t_player));
	game.map->map_path = av[1];
	game.map->gnl_count = 0;
	if (check_map(&game)) //error_managment;
	{
		printf("map error\n");
		exit(1);
	}
	game.libx->mlx = mlx_init();
	game.libx->win = mlx_new_window(game.libx->mlx, 1920, 1080, "cub3d");
	printf("%p\n", game.libx->mlx);
	
	
	game.img->big_img = mlx_new_image(game.libx->mlx, 1920, 1080);
	game.img->addr = mlx_get_data_addr(game.img->big_img, &game.img->bits_per_pixel, &game.img->line_length, &game.img->endian);
	my_mlx_pixel_put(&game, 100, 100, 0x00FF0000);
	my_mlx_pixel_put(&game, 100, 101, 0x00FF0000);
	my_mlx_pixel_put(&game, 100, 102, 0x00FF0000);
	mlx_put_image_to_window(game.libx->mlx, game.libx->win, game.img->big_img, 0, 0);
	
	
	mlx_mouse_hook(game.libx->win, mouse_hook, &game);
	mlx_hook(game.libx->win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx->win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx->mlx);
	return(0);
}