/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:16 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/28 12:42:31 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hand_state(t_game *game)
{
	static int	counter;

	if (++counter > 5)
	{
		counter = 0;
		if (++game->img.hand.left_hand == 4)
			game->img.hand.left_hand = 0;
		if (++game->img.hand.right_hand == 16 && !game->img.hand.attack)
			game->img.hand.right_hand = 10;
		else if (game->img.hand.right_hand == 27)
		{
			game->img.hand.attack = 0;
			game->img.hand.right_hand = 4;
		}
	}
}

int	hook_event(t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, \
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	start(game);
	move(game);
	mlx_put_image_to_window(game->libx.mlx, \
		game->libx.win, game->img.img, 0, 0);
	return (0);
}

void	key_right(t_game *game)
{
	game->player.direction -= 1;
	if (game->player.direction < 0)
		game->player.direction += 360;
}

void	key_left(t_game *game)
{
	game->player.direction += 1;
	if (game->player.direction >= 360)
		game->player.direction -= 360;
}

void	move(t_game *game)
{
	if (game->settings.key_a == 1)
		key_a(game);
	if (game->settings.key_s == 1)
		key_s(game);
	if (game->settings.key_d == 1)
		key_d(game);
	if (game->settings.key_w == 1)
		key_w(game);
	if (game->settings.key_left == 1)
		key_left(game);
	if (game->settings.key_right == 1)
		key_right(game);
	if (game->settings.key_up == 1)
	{
		game->mouse_horizontal += 30;
		if (game->mouse_horizontal > (SCREEN_LEN / 2))
			game->mouse_horizontal = (SCREEN_LEN / 2);
	}
	if (game->settings.key_down == 1)
	{
		game->mouse_horizontal -= 30;
		if (game->mouse_horizontal < -(SCREEN_LEN / 2))
			game->mouse_horizontal = -(SCREEN_LEN / 2);
	}
}
