/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keys_walk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:13 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/17 22:28:21 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_collision(t_game *game, float x, float y)
{
	if (game->map.map[(int)(y) / 100][(int)(x - 20) / 100] != '1' && \
		game->map.map[(int)(y) / 100][(int)(x) / 100] != '1' && \
		game->map.map[(int)(y) / 100][(int)(x + 20) / 100] != '1' && \
		game->map.map[(int)(y) / 100][(int)(x - 20) / 100] != 'C' && \
		game->map.map[(int)(y) / 100][(int)(x) / 100] != 'C' && \
		game->map.map[(int)(y) / 100][(int)(x + 20) / 100] != 'C')
	{
		if (game->map.map[(int)(y + 20) / 100][(int)(x - 20) / 100] != '1' \
			&& game->map.map[(int)(y + 20) / 100][(int)(x) / 100] != '1' && \
			game->map.map[(int)(y + 20) / 100][(int)(x + 20) / 100] != '1' && \
			game->map.map[(int)(y + 20) / 100][(int)(x - 20) / 100] != 'C' && \
			game->map.map[(int)(y + 20) / 100][(int)(x) / 100] != 'C' && \
			game->map.map[(int)(y + 20) / 100][(int)(x + 20) / 100] != 'C')
		{
			if (game->map.map[(int)(y - 20) / 100][(int)(x - 20) / 100] != '1' \
				&& game->map.map[(int)(y - 20) / 100][(int)(x) / 100] != '1' && \
				game->map.map[(int)(y - 20) / 100][(int)(x + 20) \
				/ 100] != '1' && \
				game->map.map[(int)(y - 20) / 100][(int)(x - 20) / 100] != 'C' \
				&& game->map.map[(int)(y - 20) / 100][(int)(x) / 100] != 'C' && \
				game->map.map[(int)(y - 20) / 100][(int)(x + 20) / 100] != 'C')
				return (1);
		}
	}
	return (0);
}

void	key_a(t_game *game)
{
	float	offset;

	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;
	offset = game->player.pos_x + \
		round_double(5 * (cos(deg_to_rad(game->player.direction))));
		game->player.pos_x = offset;
	offset = game->player.pos_y - \
		round_double(5 * (sin(deg_to_rad(game->player.direction))));
	game->player.pos_y = offset;
	game->player.direction -= 90;
	if (game->player.direction < 0)
		game->player.direction += 360;
}

void	key_d(t_game *game)
{
	float	offset;

	game->player.direction -= 90;
	if (game->player.direction < 0)
		game->player.direction += 360;
	offset = game->player.pos_x + \
		round_double(5 * (cos(deg_to_rad(game->player.direction))));
		game->player.pos_x = offset;
	offset = game->player.pos_y - \
		round_double(5 * (sin(deg_to_rad(game->player.direction))));
		game->player.pos_y = offset;
	game->player.direction += 90;
	if (game->player.direction >= 360)
		game->player.direction -= 360;
}

void	key_w(t_game *game)
{
	float	offset;

	offset = game->player.pos_x + round_double(10 * \
		(cos(deg_to_rad(game->player.direction))));
		game->player.pos_x = offset;
	offset = game->player.pos_y - \
		round_double(10 * (sin(deg_to_rad(game->player.direction))));
		game->player.pos_y = offset;
}

void	key_s(t_game *game)
{
	float	offset;

	offset = game->player.pos_x - \
		round_double(10 * (cos(deg_to_rad(game->player.direction))));
		game->player.pos_x = offset;
	offset = game->player.pos_y + \
		round_double(10 * (sin(deg_to_rad(game->player.direction))));
		game->player.pos_y = offset;
}
