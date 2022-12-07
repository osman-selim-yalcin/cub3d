
#include "cub3d.h"

int tmp_exit(void)
{
	exit(0);
}

int main(int ac, char **av)
{
	t_game game;
	fill_struct_map(&game, av);
	if (check_map(&game, ac))
		return (1);
	get_value(&game);
	game.img.hands[0].img = mlx_xpm_file_to_image(game.libx.mlx, "images/hand/1192_800.xpm", &game.img.hands[0].x, &game.img.hands[0].y);
	game.img.hands[1].img = mlx_xpm_file_to_image(game.libx.mlx, "images/hand/1181.xpm", &game.img.hands[1].x, &game.img.hands[1].y);
	printf("deneme\n");


	mlx_mouse_hide();
	mlx_mouse_move(game.libx.win, SCREEN_WID / 2, SCREEN_LEN / 2);
	mlx_loop_hook(game.libx.mlx, hook_event, &game);
	mlx_hook(game.libx.win, 2,  0, key_event_down, &game);
	mlx_hook(game.libx.win, 3,  0, key_event_up, &game);
	mlx_hook(game.libx.win, 6, 0L, mouse_move, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}
