/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_door_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:10 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 00:04:19 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_e(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.doors && game->map.doors[i])
	{
		if ((game->player.pos_x - game->map.doors[i][0] < 150 && \
			game->player.pos_x - game->map.doors[i][0] > -150) && \
				(game->player.pos_y - game->map.doors[i][1] < 150 && \
					game->player.pos_y - game->map.doors[i][1] > -150))
		{
			if (game->map.map[game->map.doors[i][1] / 100] \
				[game->map.doors[i][0] / 100] == 'C')
				game->map.map[game->map.doors[i][1] / 100] \
					[game->map.doors[i][0] / 100] = 'O';
			else if (game->map.map[game->map.doors[i][1] / 100] \
				[game->map.doors[i][0] / 100] == 'O' && \
				hypot(game->player.pos_x - game->map.doors[i][0], \
					game->player.pos_y - game->map.doors[i][1]) > 70)
				game->map.map[game->map.doors[i][1] / 100] \
				[game->map.doors[i][0] / 100] = 'C';
		}
		i++;
	}
}
