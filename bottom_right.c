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
	double hor = 100 - game->player.pos_x % 100;
	double ver = 100 - game->player.pos_y % 100;
	double y;
	double hypo = 0;
	while (1) //east texture //270 handle
	{
		y = tan(deg_to_rad(game->player.ray_abs - 270)) * hor;
		if (find_wall_vertical_four(game->player.pos_x + hor, game->player.pos_y + y, game))
		{
			if (find_wall_vertical_four(game->player.pos_x + hor, game->player.pos_y + y, game) == 1)
				hypo = hypot(y, hor);
			break;
		}
		hor += 100;
	}
	while (1) // north texture
	{
		y = (1 /tan(deg_to_rad(game->player.ray_abs - 270))) * ver;
		if (find_wall_horizontal_four(game->player.pos_x + y, game->player.pos_y + ver, game))
			break;
		ver += 100;
	}
	if (hypo > hypot(y, ver) || hypo == 0)
	{
		hypo = hypot(y,ver);
	}
	game->img.color = 0x90FF00FF;
	pixelput(game, hypo, ray_counter);
}