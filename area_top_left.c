/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_top_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:50:46 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 23:53:12 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	top_left_vertical_while(t_game *game, double *y, double *hypo, double *hor)
{
	if (find_wall_vertical_two(game->player.pos_x - *hor, \
	game->player.pos_y - *y, game))
	{
		if (find_wall_vertical_two(game->player.pos_x - *hor, \
		game->player.pos_y - *y, game) == 1)
		{
			game->img.wall_x = game->img.east_x * ((int) \
			((game->player.pos_y - *y) * 100) % 10000) / 10000;
			game->img.which_wall = 4;
			*hypo = hypot(*y, *hor);
		}
		else if (find_wall_vertical_two(game->player.pos_x - *hor, \
		game->player.pos_y - *y, game) == 3)
		{
			game->img.wall_x = game->img.door_x * ((int) \
			((game->player.pos_y - *y) * 100) % 10000) / 10000;
			game->img.which_wall = 7;
			*hypo = hypot(*y, *hor);
		}
		return (1);
	}
	return (0);
}

void	top_left_vertical(t_game *game, double *y, double *hypo)
{
	double	hor;

	hor = (int)game->player.pos_x % 100;
	while (1)
	{
		if (game->player.ray_abs == 90)
			break ;
		*y = fabs(tan(deg_to_rad(game->player.ray_abs))) * hor;
		if (top_left_vertical_while(game, y, hypo, &hor))
			break ;
		hor += 100;
	}
}

void	top_left_find_hypo(t_game *game, double *y \
	, double *ver, double *hypo)
{
	if (*hypo > hypot(*y, *ver) || *hypo == 0)
	{
		if (find_wall_horizontal_two(game->player.pos_x - *y, \
		game->player.pos_y - *ver, game) == 3)
		{
			game->img.wall_x = game->img.door_x * ((int) \
			((game->player.pos_x - *y) * 100) % 10000) / 10000;
			game->img.which_wall = 7;
		}
		else
		{
			game->img.wall_x = game->img.south_x * ((int) \
			((game->player.pos_x - *y) * 100) % 10000) / 10000;
			game->img.which_wall = 3;
		}
		*hypo = hypot(*y, *ver);
	}
	*hypo = *hypo * fabs(cos(deg_to_rad(game->player.ray_abs - \
	game->player.direction)));
}

void	top_left(t_game *game, double ray_counter)
{
	double	ver;
	double	y;
	double	hypo;

	ver = (int)game->player.pos_y % 100;
	hypo = 0;
	top_left_vertical(game, &y, &hypo);
	while (1)
	{
		y = (1 / fabs(tan(deg_to_rad(game->player.ray_abs)))) * ver;
		if (find_wall_horizontal_two(game->player.pos_x - y, \
			game->player.pos_y - ver, game))
			break ;
		ver += 100;
	}
	top_left_find_hypo(game, &y, &ver, &hypo);
	pixelput(game, hypo, ray_counter);
}
