
#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

int main(int ac, char **av)
{
	t_game game;
	fill_struct_map(&game, av);
	if (check_map(&game, ac))
		return (1);
	get_value(&game);

//tmp area;!!!
	game.player.hp = 4;
	print_frame(&game, 2);
	game.player.hp_count = 50;
//tmp area;!!!

	mlx_mouse_hide();
	mlx_mouse_move(game.libx.win, SCREEN_WID / 2, SCREEN_LEN / 2);
	mlx_loop_hook(game.libx.mlx, hook_event, &game);
	mlx_hook(game.libx.win, 2,  0, key_event_down, &game);
	mlx_hook(game.libx.win, 3,  0, key_event_up, &game);
	mlx_hook(game.libx.win, 6, 0L, mouse_move, &game);
	mlx_mouse_hook(game.libx.win, &temporary_killer, &game); //to be changed
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}
