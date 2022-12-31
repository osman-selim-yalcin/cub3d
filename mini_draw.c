/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:48:40 by burak             #+#    #+#             */
/*   Updated: 2022/12/31 23:50:15 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini_wall(t_game *game, int x, int y)
{
	int	x2;
	int	y2;

	x2 = -1;
	while (++x2 <= game->settings.minimap_scale)
	{
		y2 = -1;
		while (++y2 <= game->settings.minimap_scale)
		{
			if (x2 < game->settings.minimap_scale / 10 || x2 >= \
				game->settings.minimap_scale - (game->settings.minimap_scale \
				/ 10) || y2 < game->settings.minimap_scale / 10 || y2 >= \
				game->settings.minimap_scale - (game->settings.minimap_scale \
				/ 10) || x2 == 0 || y2 == 0)
				my_mlx_pixel_put(game, (x - game->minimap.empty_column) * \
					game->settings.minimap_scale + x2 + game->minimap.shift_x, \
					y * game->settings.minimap_scale + y2 + \
					game->minimap.shift_y, 0x007b2d26);
			else
				my_mlx_pixel_put(game, (x - game->minimap.empty_column) * \
					game->settings.minimap_scale + x2 + game->minimap.shift_x, \
					y * game->settings.minimap_scale + y2 + \
					game->minimap.shift_y, 0x00d7c9aa);
		}
	}
}

void	draw_mini_door(t_game *game, int x, int y)
{
	int	x2;
	int	y2;

	x2 = -1;
	while (++x2 <= game->settings.minimap_scale)
	{
		y2 = -1;
		while (++y2 <= game->settings.minimap_scale)
		{
			if (x2 < game->settings.minimap_scale / 10 || x2 >= \
			game->settings.minimap_scale - (game->settings.minimap_scale \
			/ 10) || y2 < game->settings.minimap_scale / 10 || y2 >= \
				game->settings.minimap_scale - \
				(game->settings.minimap_scale / 10) || x2 == 0 || y2 == 0)
				my_mlx_pixel_put(game, (x - game->minimap.empty_column) * \
					game->settings.minimap_scale + x2 + \
					game->minimap.shift_x, y * game->settings.minimap_scale \
					+ y2 + game->minimap.shift_y, 0x00FF6B00);
			else
				my_mlx_pixel_put(game, (x - game->minimap.empty_column) * \
					game->settings.minimap_scale + x2 + \
					game->minimap.shift_x, y * game->settings.minimap_scale \
					+ y2 + game->minimap.shift_y, 0x009ea3b0);
		}
	}
}
