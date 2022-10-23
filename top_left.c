#include "cub3d.h"

int find_wall_vertical_two(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	hor--;
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

int find_wall_horizontal_two(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	ver--;
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

void top_left(t_game *game, double ray_counter)
{
	double hor = game->player.pos_x % 100;
	double ver = game->player.pos_y % 100;
	double y;
	double hypo = 0;
	while (1)//east texture  //117 çok büyük eksi çıkıyo haritada N gir ve 117 açıya bak eğer gerekirse
	{
		if (game->player.ray_abs == 90)
			break;
		y = fabs(tan(deg_to_rad(game->player.ray_abs))) * hor;
		if (find_wall_vertical_two(game->player.pos_x - hor, game->player.pos_y - y, game))
		{
			if (find_wall_vertical_two(game->player.pos_x - hor, game->player.pos_y - y, game) == 1)
			{
				game->img.wall_x = 64 * ((int)(game->player.pos_y - y) % 100) / 100;
				game->img.which_wall = 4;
				hypo = hypot(y,hor);
			}
			break;
		}
		hor += 100;
	}
	while (1) //south texture
	{
		y = (1 / fabs(tan(deg_to_rad(game->player.ray_abs)))) * ver;
		if (find_wall_horizontal_two(game->player.pos_x - y, game->player.pos_y - ver, game))
			break;
		ver += 100;
	}
	if (hypo > hypot(y, ver) || hypo == 0)
	{
		game->img.wall_x = 64 * ((int)(game->player.pos_x - y) % 100) / 100;
		game->img.which_wall = 3;
		hypo = hypot(y,ver);
	}
	hypo = hypo * fabs(cos(deg_to_rad(game->player.ray_abs - game->player.direction)));
	pixelput(game, hypo, ray_counter);
}