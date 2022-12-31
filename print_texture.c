/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:21:44 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/12/31 22:30:55 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	take_texture(t_game *game, int x, int y, int which_wall)
{
	char	*dst;

	dst = NULL;
	if (which_wall == 1)
		dst = game->img.north_addr + (y * game->img.north_line_length \
		+ x * (game->img.north_bits_per_pixel / 8));
	else if (which_wall == 2)
		dst = game->img.west_addr + (y * game->img.west_line_length + \
		x * (game->img.west_bits_per_pixel / 8));
	else if (which_wall == 3)
		dst = game->img.south_addr + (y * game->img.south_line_length + \
		x * (game->img.south_bits_per_pixel / 8));
	else if (which_wall == 4)
		dst = game->img.east_addr + (y * game->img.east_line_length + \
		x * (game->img.east_bits_per_pixel / 8));
	else if (which_wall == 7)
		dst = game->img.door_addr + (y * game->img.door_line_length + \
		x * (game->img.door_bits_per_pixel / 8));
	else if (which_wall == 10)
		dst = game->img.hand.hand_img[game->img.hand.left_hand].addr + (y * \
		game->img.hand.hand_img[game->img.hand.left_hand].line_length + x * \
		(game->img.hand.hand_img[game->img.hand.left_hand].bits_per_pixel / 8));
	else if (which_wall == 11)
		dst = game->img.hand.hand_img[game->img.hand.right_hand].addr + (y * \
		game->img.hand.hand_img[game->img.hand.right_hand].line_length + x * \
		(game->img.hand.hand_img[game->img.hand.right_hand].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
