#include "cub3d.h"

void get_enemy(t_game *game)
{
	int angle;
	
	game->enemy.distance = hypot(game->enemy.posx - game->player.pos_x, game->enemy.posy - game->player.pos_y);
	angle = rad_to_deg(atan((game->enemy.posx - game->player.pos_x) / (game->enemy.posy - game->player.pos_y)));
	
	game->enemy.width = (10 + 20 / game->enemy.distance);
	int x = sin(deg_to_rad(angle + 90)) * game->enemy.width; //(5 + 20 / game->enemy.distance); //sağ kol // x
	int y = cos(deg_to_rad(angle + 90)) * game->enemy.width; // y
	
	int angle1;
	angle1 = rad_to_deg(atan(fabs(game->enemy.posx + x - game->player.pos_x) / fabs(game->enemy.posy + y - game->player.pos_y)));

	x = sin(deg_to_rad(angle - 90)) * game->enemy.width;//sol kol
	y = cos(deg_to_rad(angle - 90)) * game->enemy.width;
	
	int angle2 = rad_to_deg(atan(fabs(game->enemy.posx + x - game->player.pos_x) / fabs(game->enemy.posy + y - game->player.pos_y))); 
	
	game->enemy.start = angle1;
	game->enemy.finish = angle2;
	game->enemy.total_ray = 1920 * fabs(game->enemy.start - game->enemy.finish) / D_FOV;
	game->enemy.count = 0;
}