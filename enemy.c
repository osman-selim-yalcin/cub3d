#include "cub3d.h"

void get_enemy(t_game *game)
{
	int angle;
	
	game->enemy.distance = hypot(game->enemy.posx - game->player.pos_x, game->enemy.posy - game->player.pos_y);
	if (game->enemy.posy - game->player.pos_y == 0)
	{
		if (game->enemy.posx > game->player.pos_x)
			angle = 0;
		else
			angle = 90;
	}	
	else if (game->enemy.posx - game->player.pos_x == 0)
	{
		if (game->enemy.posy > game->player.pos_y)
			angle = 270;
		else
			angle = 90;
	}
	else
		angle = rad_to_deg(atan((game->enemy.posx - game->player.pos_x) / (game->enemy.posy - game->player.pos_y)));

	game->enemy.width = (10 + 20 / game->enemy.distance);
	int x = sin(deg_to_rad(angle - 90)) * game->enemy.width / 2; //(5 + 20 / game->enemy.distance); //sağ kol // x
	int y = cos(deg_to_rad(angle - 90)) * game->enemy.width / 2; // y
	
	int angle1;
	angle1 = rad_to_deg(atan((game->enemy.posx + x - game->player.pos_x) / (game->enemy.posy + y - game->player.pos_y)));

	x = sin(deg_to_rad(angle + 90)) * game->enemy.width / 2;//sol kol
	y = cos(deg_to_rad(angle + 90)) * game->enemy.width / 2;
	
	int angle2 = rad_to_deg(atan((game->enemy.posx + x - game->player.pos_x) / (game->enemy.posy + y - game->player.pos_y))); 
	
	
	if (game->enemy.posy > game->player.pos_y)
	{
		if (game->enemy.posx > game->player.pos_x)
		{
			angle1 += 270;
			angle2 += 270;
		}	
		else
		{
			angle1 += 180;
			angle2 += 180;
		}
	}
	else
	{
		if (game->enemy.posx > game->player.pos_x)
		{
			angle1 += 0;
			angle2 += 0;
		}
		else
		{
			angle1 += 90;
			angle2 += 90;
		}
	}
	if (angle1 < 0)
	{
		angle1 += 360;
	}
	if (angle2 < 0)
	{
		angle2 += 360;
	}
	if (angle1 >= 360)
	{
		angle1 -= 360;
	}
	if (angle2 >= 360)
	{
		angle2 -= 360;
	}
	game->enemy.start = angle1;
	game->enemy.finish = angle2;
	game->enemy.total_ray = 1920 * fabs(game->enemy.start - game->enemy.finish) / D_FOV;
	game->enemy.count = 0;
	// printf("game enemy.start %lf finish %lf  total ray %d\n", game->enemy.start,game->enemy.finish,game->enemy.total_ray);
}