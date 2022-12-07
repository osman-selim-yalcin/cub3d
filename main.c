
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
	game.img.hand.hand_img[0].img = mlx_xpm_file_to_image(game.libx.mlx, "images/hand/192.xpm", &game.img.hand.hand_img[0].x, &game.img.hand.hand_img[0].y);
	game.img.hand.hand_img[0].addr = mlx_get_data_addr(game.img.hand.hand_img[0].img, &game.img.hand.hand_img[0].bits_per_pixel, &game.img.hand.hand_img[0].line_length, &game.img.hand.hand_img[0].endian);
	game.img.hand.hand_img[1].img = mlx_xpm_file_to_image(game.libx.mlx, "images/hand/181.xpm", &game.img.hand.hand_img[1].x, &game.img.hand.hand_img[1].y);
	game.img.hand.hand_img[1].addr = mlx_get_data_addr(game.img.hand.hand_img[1].img, &game.img.hand.hand_img[1].bits_per_pixel, &game.img.hand.hand_img[1].line_length, &game.img.hand.hand_img[1].endian);

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
