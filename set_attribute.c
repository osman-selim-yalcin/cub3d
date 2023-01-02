/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attribute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:02:51 by burak             #+#    #+#             */
/*   Updated: 2023/01/02 15:03:05 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_settings(t_game *game)
{
	game->settings.minimap_scale = game->minimap.full_scale / 5;
	game->settings.step_size = game->settings.minimap_scale / 10;
	game->settings.player_size = game->settings.minimap_scale / 4;
	game->settings.ray_len = 2 * game->settings.minimap_scale / 5;
	game->settings.key_a = 0;
	game->settings.key_w = 0;
	game->settings.key_s = 0;
	game->settings.key_d = 0;
	game->settings.key_right = 0;
	game->settings.key_left = 0;
	game->settings.key_up = 0;
	game->settings.key_down = 0;
	game->mouse_horizontal = 0;
}

void	set_scale_factor(t_game *game)
{
	if ((float)(game->map.total_column - game->minimap.empty_column - \
		game->minimap.empty_column2) / \
		game->map.length < (float)SCREEN_WID / SCREEN_LEN)
		game->minimap.full_scale = \
			((float)SCREEN_LEN / (game->map.length + 1)) - 1;
	else
		game->minimap.full_scale = (float)SCREEN_WID / (game->map.total_column \
			- game->minimap.empty_column - game->minimap.empty_column2 + 1);
	game->minimap.shift_x = 0;
	game->minimap.shift_y = 0;
}
