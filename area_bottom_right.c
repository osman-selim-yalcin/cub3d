/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_bottom_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:50:43 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 23:46:52 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bottom_right_vertical_while(t_game *game, \
	double *y, double *hypo, double *hor)
{
	if (find_wall_vertical_four(game->player.pos_x + *hor, \
		game->player.pos_y + *y, game))
	{
		if (find_wall_vertical_four(game->player.pos_x + *hor, \
		game->player.pos_y + *y, game) == 1)
		{
			game->img.wall_x = game->img.west_x * ((int) \
			((game->player.pos_y + *y) * 100) % 10000) / 10000;
			game->img.which_wall = 2;
			*hypo = hypot(*y, *hor);
		}
		if (find_wall_vertical_four(game->player.pos_x + *hor, \
		game->player.pos_y + *y, game) == 3)
		{
			game->img.wall_x = game->img.door_x * ((int) \
			((game->player.pos_y + *y) * 100) % 10000) / 10000;
			game->img.which_wall = 7;
			*hypo = hypot(*y, *hor);
		}
		return (1);
	}
	return (0);
}

void	bottom_right_vertical(t_game *game, double *y, double *hypo)
{
	double	hor;

	hor = 100 - (int)game->player.pos_x % 100;
	while (1)
	{
		if (game->player.ray_abs == 270)
			break ;
		*y = fabs(tan(deg_to_rad(game->player.ray_abs))) * hor;
		if (bottom_right_vertical_while(game, y, hypo, &hor))
			break ;
		hor += 100;
	}
}

void	bottom_right_find_hypo(t_game *game, double *y, \
	double *ver, double *hypo)
{
	if (*hypo > hypot(*y, *ver) || *hypo == 0)
	{
		if (find_wall_horizontal_four(game->player.pos_x + *y, \
			game->player.pos_y + *ver, game) == 3)
		{
			game->img.wall_x = game->img.door_x * ((int) \
				((game->player.pos_x + *y) * 100) % 10000) / 10000;
			game->img.which_wall = 7;
		}
		else
		{
			game->img.wall_x = game->img.north_x * ((int) \
				((game->player.pos_x + *y) * 100) % 10000) / 10000;
			game->img.which_wall = 1;
		}
		*hypo = hypot(*y, *ver);
	}
	*hypo = *hypo * fabs(cos(deg_to_rad(game->player.ray_abs \
		- game->player.direction)));
}

void	bottom_right(t_game *game, double ray_counter)
{
	double	ver;
	double	y;
	double	hypo;

	ver = 100 - (int)game->player.pos_y % 100;
	hypo = 0;
	bottom_right_vertical(game, &y, &hypo);
	while (1)
	{
		y = (1 / fabs(tan(deg_to_rad(game->player.ray_abs)))) * ver;
		if (find_wall_horizontal_four(game->player.pos_x + y, \
			game->player.pos_y + ver, game))
			break ;
		ver += 100;
	}
	bottom_right_find_hypo(game, &y, &ver, &hypo);
	pixelput(game, hypo, ray_counter);
}
