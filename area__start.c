/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area__start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:49:59 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/12/31 21:50:31 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start(t_game *game)
{
	double	ray_counter;

	ray_counter = 0;
	while (ray_counter < SCREEN_WID)
	{
		game->player.ray_abs = (game->player.direction - game->player.fov / 2) + (ray_counter / SCREEN_WID * D_FOV);
		if (game->player.ray_abs < 0)
			game->player.ray_abs += 360;
		else if (game->player.ray_abs >= 360)
			game->player.ray_abs -= 360;
		if (ray_angle(game) == 1)
		{
			top_right(game, ray_counter);
		}
		else if (ray_angle(game) == 2)
		{
			top_left(game, ray_counter);
		}
		else if (ray_angle(game) == 3)
		{
			bottom_left(game,ray_counter);
		}
		else if (ray_angle(game) == 4)
		{
			bottom_right(game, ray_counter);
		}
		ray_counter += 1;
	}
}