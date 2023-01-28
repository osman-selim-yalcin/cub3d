/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_bottom_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:50:41 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/28 12:42:42 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bottom_left_vertical_while(t_game *game, double *hypo, \
	double *y, double *hor)
{
	if (find_wall_vertical_three(game->player.pos_x - *hor, \
		game->player.pos_y + *y, game))
	{
		if (find_wall_vertical_three(game->player.pos_x - *hor, \
			game->player.pos_y + *y, game) == 1)
		{
			game->img.wall_x = game->img.east_x * ((int) \
				((game->player.pos_y + *y) * 100) % 10000) / 10000;
			game->img.which_wall = 4;
			*hypo = hypot(*y, *hor);
		}
		else if (find_wall_vertical_three(game->player.pos_x - *hor, \
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

void	bottom_left_vertical(t_game *game, double *hypo, double *y)
{
	double	hor;

	hor = (int)game->player.pos_x % 100;
	while (1)
	{
		*y = fabs(tan(deg_to_rad(game->player.ray_abs))) * hor;
		if (bottom_left_vertical_while(game, hypo, y, &hor))
			break ;
		hor += 100;
	}
}

void	bottom_left_find_hypo(t_game *game, double *ver, \
	double *y, double *hypo)
{
	if ((*hypo > hypot(*y, *ver) || *hypo == 0))
	{
		if (find_wall_horizontal_three(game->player.pos_x - *y, \
		game->player.pos_y + *ver, game) == 3)
		{
			game->img.wall_x = game->img.door_x * ((int) \
			((game->player.pos_x - *y) * 100) % 10000) / 10000;
			game->img.which_wall = 7;
		}
		else
		{
			game->img.wall_x = game->img.north_x * ((int) \
			((game->player.pos_x - *y) * 100) % 10000) / 10000;
			game->img.which_wall = 1;
		}
		*hypo = hypot(*y, *ver);
	}
	*hypo = *hypo * fabs(cos(deg_to_rad(game->player.ray_abs - \
	game->player.direction)));
}

void	bottom_left(t_game *game, double ray_counter)
{
	double	ver;
	double	y;
	double	hypo;

	ver = 100 - (int)game->player.pos_y % 100;
	hypo = 0;
	bottom_left_vertical(game, &hypo, &y);
	while (1)
	{
		y = (1 / fabs(tan(deg_to_rad(game->player.ray_abs)))) * ver;
		if (find_wall_horizontal_three(game->player.pos_x - y, \
			game->player.pos_y + ver, game))
			break ;
		ver += 100;
	}
	bottom_left_find_hypo(game, &ver, &y, &hypo);
	pixelput(game, hypo, ray_counter);
}
