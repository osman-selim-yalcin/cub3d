/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hand_img_56.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:57:32 by burak             #+#    #+#             */
/*   Updated: 2023/01/02 14:57:56 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hand_struct_5(t_game *game)
{
	game->img.hand.hand_img[20].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/199.xpm", &game->img.hand.hand_img[20].x, \
		&game->img.hand.hand_img[20].y);
	game->img.hand.hand_img[20].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[20].img, &game->img.hand.hand_img[20].bits_per_pixel, &game->\
		img.hand.hand_img[20].line_length, &game->img.hand.hand_img[20].endian);
	game->img.hand.hand_img[21].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/200.xpm", &game->img.hand.hand_img[21].x, \
		&game->img.hand.hand_img[21].y);
	game->img.hand.hand_img[21].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[21].img, &game->img.hand.hand_img[21].bits_per_pixel, &game->\
		img.hand.hand_img[21].line_length, &game->img.hand.hand_img[21].endian);
	game->img.hand.hand_img[22].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/201.xpm", &game->img.hand.hand_img[22].x, \
		&game->img.hand.hand_img[22].y);
	game->img.hand.hand_img[22].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[22].img, &game->img.hand.hand_img[22].bits_per_pixel, &game->\
		img.hand.hand_img[22].line_length, &game->img.hand.hand_img[22].endian);
	game->img.hand.hand_img[23].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/202.xpm", &game->img.hand.hand_img[23].x, \
		&game->img.hand.hand_img[23].y);
	game->img.hand.hand_img[23].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[23].img, &game->img.hand.hand_img[23].bits_per_pixel, &game->\
		img.hand.hand_img[23].line_length, &game->img.hand.hand_img[23].endian);
}

void	set_hand_struct_6(t_game *game)
{
	game->img.hand.hand_img[24].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/203.xpm", &game->img.hand.hand_img[24].x, \
		&game->img.hand.hand_img[24].y);
	game->img.hand.hand_img[24].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[24].img, &game->img.hand.hand_img[24].bits_per_pixel, &game->\
		img.hand.hand_img[24].line_length, &game->img.hand.hand_img[24].endian);
	game->img.hand.hand_img[25].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/204.xpm", &game->img.hand.hand_img[25].x, \
		&game->img.hand.hand_img[25].y);
	game->img.hand.hand_img[25].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[25].img, &game->img.hand.hand_img[25].bits_per_pixel, &game->\
		img.hand.hand_img[25].line_length, &game->img.hand.hand_img[25].endian);
	game->img.hand.hand_img[26].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/205.xpm", &game->img.hand.hand_img[26].x, \
		&game->img.hand.hand_img[26].y);
	game->img.hand.hand_img[26].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[26].img, &game->img.hand.hand_img[26].bits_per_pixel, &game->\
		img.hand.hand_img[26].line_length, &game->img.hand.hand_img[26].endian);
}
