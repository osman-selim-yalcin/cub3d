#include "cub3d.h"

void	draw_weapon(t_game *game) //burak bu ne aga
{
	int		i;
	int		j;
	void	*img;

	img = mlx_xpm_file_to_image(game->libx.mlx, "images/weapon/weapon1.xpm", &i, &j);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, img, 0, 0);
	mlx_destroy_image(game->libx.mlx, img);
}