#include "cub3d.h"

void get_enemy(t_game *game)
{
	double middle;
	int k;

	game->player.ray_start = (game->player.direction - game->player.fov / 2);
	if (game->player.ray_start < 0)
		game->player.ray_start += 360;

	game->enemy.distance = hypot(game->enemy.posx - game->player.pos_x, game->enemy.posy - game->player.pos_y);
	game->enemy.width = ((30 * SCREEN_WID) / (game->enemy.distance * 2));
	
	middle = atan((game->enemy.posx - game->player.pos_x) / (game->enemy.posy - game->player.pos_y));
	if (game->player.pos_x > game->enemy.posx)
	{
		if (game->player.pos_y > game->enemy.posy)
			middle += deg_to_rad(90);
		else		
			middle = middle + deg_to_rad(270);
	}
	else
	{
		if (game->player.pos_y > game->enemy.posy)
			middle += deg_to_rad(90);
		else
			middle += deg_to_rad(270);
	}
	
	
	k = 0;
	while (game->player.ray_start + k != rad_to_deg(middle))
	{
		k++;
		if ((int)(game->player.ray_start + k) % 360 == rad_to_deg(middle))
			break;
	}

	game->enemy.pixel = SCREEN_WID * (k) / D_FOV;
	while (game->enemy.pixel > SCREEN_WID * 5)
		game->enemy.pixel -= SCREEN_WID * 6;

	game->enemy.middle = middle;
	game->enemy.count = 0;
}