#include "cub3d.h"

int find_wall_vertical_one(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (hor <= 0 || hor > game->map.width || ver <= 0 || ver > game->map.length)
 	{
		return (2);
	}
	if (game->map.map[(int)(ver)][(int)(hor)] == '2')
	{
		return(2);
	}
	if (game->map.map[(int)(ver)][(int)(hor)] == '1')
	{
		return (1);
	}
	if (game->map.map[(int)(ver)][(int)(hor)] == 'C')
	{
		return (3);
	}
	return (0);
}

int find_wall_horizontal_one(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	ver--;
	if (hor <= 0 || hor > game->map.width || ver <= 0 || ver > game->map.length)
	{
		return (2);
	}
	if (game->map.map[(int)(ver)][(int)(hor)] == '2')
	{
		return(2);
	}
	if (game->map.map[(int)(ver)][(int)(hor)] == '1')
	{
		return (1);
	}
	if (game->map.map[(int)(ver)][(int)(hor)] == 'C')
	{
		return (3);
	}
	return (0);
}

void top_right(t_game *game, double ray_counter)
{
	double hor = 100 - (int)game->player.pos_x % 100;
	double ver = (int)game->player.pos_y % 100;
	double y;
	double hypo = 0;

	while (1) //west texture
	{ 
		y = tan(deg_to_rad(game->player.ray_abs)) * hor;
		if(find_wall_vertical_one(hor + game->player.pos_x, game->player.pos_y - y, game))
		{
			if (find_wall_vertical_one(hor + game->player.pos_x, game->player.pos_y - y, game) == 1)
			{
				game->img.wall_x = game->img.west_x * ((int)((game->player.pos_y - y) * 100) % 10000) / 10000;
				game->img.which_wall = 2;
				hypo = hypot(y,hor);
			}
			else if (find_wall_vertical_one(hor + game->player.pos_x, game->player.pos_y - y, game) == 3) // door
			{
				game->img.wall_x = game->img.door_x * ((int)((game->player.pos_y - y) * 100) % 10000) / 10000;
				game->img.which_wall = 7;
				hypo = hypot(y,hor);
			}
			break;
		}
		hor += 100;
	}
	while (1) //south texture
	{
		if (game->player.ray_abs == 0)
			break;
		y = (1 / tan(deg_to_rad(game->player.ray_abs))) * ver;
		if (find_wall_horizontal_one(game->player.pos_x + y, game->player.pos_y - ver, game))
			break;
		ver += 100;
	}
	if ((hypo > hypot(y, ver) || hypo == 0) && (game->player.ray_abs != 0))
	{
		if (find_wall_horizontal_one(game->player.pos_x + y, game->player.pos_y - ver, game) == 3) // door
		{
			game->img.wall_x = game->img.door_x * ((int)((game->player.pos_x + y) * 100) % 10000) / 10000;
			game->img.which_wall = 7;
		}
		else
		{
			game->img.wall_x = game->img.south_x * ((int)((game->player.pos_x + y) * 100) % 10000) / 10000;
			game->img.which_wall = 3;
		}
		hypo = hypot(y,ver);
	}
	hypo = hypo * fabs(cos(deg_to_rad(game->player.ray_abs - game->player.direction)));
	pixelput(game, hypo, ray_counter);
}