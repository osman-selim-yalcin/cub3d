#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

// void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

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

	get_value(&game, av);
	if (check_map(&game, ac)) //error_managment;
		return (1);
	game.libx.mlx = mlx_init();
	game.libx.win = mlx_new_window(game.libx.mlx, 1920, 1080, "cub3d");

	system("leaks cub3d");
	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return(0);
}