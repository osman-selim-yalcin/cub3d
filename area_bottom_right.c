#include "cub3d.h"

int find_wall_vertical_four(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (ver <= 0 || ver > game->map.length)
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
	return (0);
}

int find_wall_horizontal_four(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (hor <= 0 || hor > game->map.width)
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
	return (0);
}

void bottom_right(t_game *game, double ray_counter)
{
	double hor = 100 - (int)game->player.pos_x % 100;
	double ver = 100 - (int)game->player.pos_y % 100;
	double y;
	double hypo = 0;
	while (1) //west texture //270 handle
	{
		if (game->player.ray_abs == 270)
			break;
		y = fabs(tan(deg_to_rad(game->player.ray_abs))) * hor;
		if (find_wall_vertical_four(game->player.pos_x + hor, game->player.pos_y + y, game))
		{
			if (find_wall_vertical_four(game->player.pos_x + hor, game->player.pos_y + y, game) == 1)
			{
				game->img.wall_x = game->img.west_x * ((int)(game->player.pos_y + y) % 100) / 100;
				game->img.which_wall = 2;
				hypo = hypot(y, hor);
			}
			break;
		}
		hor += 100;
	}
	while (1) // north texture
	{
		y = (1 / fabs(tan(deg_to_rad(game->player.ray_abs)))) * ver;
		if (find_wall_horizontal_four(game->player.pos_x + y, game->player.pos_y + ver, game))
			break;
		ver += 100;
	}
	if (hypo > hypot(y, ver) || hypo == 0)
	{
		game->img.wall_x = game->img.north_x * ((int)(game->player.pos_x + y) % 100) / 100;
		game->img.which_wall = 1;
		hypo = hypot(y,ver);
	}
	hypo = hypo * fabs(cos(deg_to_rad(game->player.ray_abs - game->player.direction)));
	pixelput(game, hypo, ray_counter);
}