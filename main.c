#include "cub3d.h"

int main()
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1024, 1024, "lol");
	
	return(0);
}