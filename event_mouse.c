/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:19 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/12/31 22:13:10 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	int	b;
	int	a;

	b = (y - (SCREEN_LEN / 2)) / 3;
	if ((game->mouse_horizontal - b > -(SCREEN_LEN / 2)) \
		&& (game->mouse_horizontal - b < SCREEN_LEN / 2))
		game->mouse_horizontal -= b;
	a = SCREEN_WID / 2 - x;
	game->player.direction += (int)SENS * (int)a / 20;
	game->minimap.pa += deg_to_rad((int)SENS * (int)a / 20);
	if (game->player.direction >= 360)
	{
		game->minimap.pa -= 2 * M_PI;
		game->player.direction -= 360;
	}
	else if (game->player.direction < 0)
	{
		game->minimap.pa += 2 * M_PI;
		game->player.direction += 360;
	}
	mlx_mouse_move(game->libx.win, SCREEN_WID / 2, SCREEN_LEN / 2);
	return (0);
}
