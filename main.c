#include "cub3d.h"

int main()
{
	t_game game;

	game.libx.mlx = mlx_init();
	if (check_map(game)); //error_managment;
	{
		;
	}
	game.libx.win = mlx_new_window(game.libx.mlx, 1024, 1024, "lol");
	
	return(0);
}