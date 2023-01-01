/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_top_right_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:44:59 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 23:59:40 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_wall_vertical_one(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	if (hor <= 0 || hor > game->map.width || ver <= 0 || ver > game->map.length)
		return (2);
	if (game->map.map[(int)(ver)][(int)(hor)] == '2')
		return (2);
	if (game->map.map[(int)(ver)][(int)(hor)] == '1')
		return (1);
	if (game->map.map[(int)(ver)][(int)(hor)] == 'C')
		return (3);
	return (0);
}

int	find_wall_horizontal_one(double hor, double ver, t_game *game)
{
	hor /= 100;
	ver /= 100;
	ver--;
	if (hor <= 0 || hor > game->map.width || ver <= 0 || ver > game->map.length)
		return (2);
	if (game->map.map[(int)(ver)][(int)(hor)] == '2')
		return (2);
	if (game->map.map[(int)(ver)][(int)(hor)] == '1')
		return (1);
	if (game->map.map[(int)(ver)][(int)(hor)] == 'C')
		return (3);
	return (0);
}
