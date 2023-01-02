/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hand_img_04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:55:55 by burak             #+#    #+#             */
/*   Updated: 2023/01/02 14:57:16 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hand_struct(t_game *game)
{
	game->img.hand.hand_img[0].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/179.xpm", &game->img.hand.hand_img[0].x, \
		&game->img.hand.hand_img[0].y);
	game->img.hand.hand_img[0].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[0].img, &game->img.hand.hand_img[0].bits_per_pixel, &game->\
		img.hand.hand_img[0].line_length, &game->img.hand.hand_img[0].endian);
	game->img.hand.hand_img[1].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/180.xpm", &game->img.hand.hand_img[1].x, \
		&game->img.hand.hand_img[1].y);
	game->img.hand.hand_img[1].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[1].img, &game->img.hand.hand_img[1].bits_per_pixel, &game->\
		img.hand.hand_img[1].line_length, &game->img.hand.hand_img[1].endian);
	game->img.hand.hand_img[2].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/181.xpm", &game->img.hand.hand_img[2].x, \
		&game->img.hand.hand_img[2].y);
	game->img.hand.hand_img[2].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[2].img, &game->img.hand.hand_img[2].bits_per_pixel, &game->\
		img.hand.hand_img[2].line_length, &game->img.hand.hand_img[2].endian);
	game->img.hand.hand_img[3].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/182.xpm", &game->img.hand.hand_img[3].x, \
		&game->img.hand.hand_img[3].y);
	game->img.hand.hand_img[3].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[3].img, &game->img.hand.hand_img[3].bits_per_pixel, &game->\
		img.hand.hand_img[3].line_length, &game->img.hand.hand_img[3].endian);
}

void	set_hand_struct_1(t_game *game)
{
	game->img.hand.hand_img[4].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/183.xpm", &game->img.hand.hand_img[4].x, \
		&game->img.hand.hand_img[4].y);
	game->img.hand.hand_img[4].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[4].img, &game->img.hand.hand_img[4].bits_per_pixel, &game->\
		img.hand.hand_img[4].line_length, &game->img.hand.hand_img[4].endian);
	game->img.hand.hand_img[5].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/184.xpm", &game->img.hand.hand_img[5].x, \
		&game->img.hand.hand_img[5].y);
	game->img.hand.hand_img[5].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[5].img, &game->img.hand.hand_img[5].bits_per_pixel, &game->\
		img.hand.hand_img[5].line_length, &game->img.hand.hand_img[5].endian);
	game->img.hand.hand_img[6].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/185.xpm", &game->img.hand.hand_img[6].x, \
		&game->img.hand.hand_img[6].y);
	game->img.hand.hand_img[6].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[6].img, &game->img.hand.hand_img[6].bits_per_pixel, &game->\
		img.hand.hand_img[6].line_length, &game->img.hand.hand_img[6].endian);
	game->img.hand.hand_img[7].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/186.xpm", &game->img.hand.hand_img[7].x, \
		&game->img.hand.hand_img[7].y);
	game->img.hand.hand_img[7].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[7].img, &game->img.hand.hand_img[7].bits_per_pixel, &game->\
		img.hand.hand_img[7].line_length, &game->img.hand.hand_img[7].endian);
}

void	set_hand_struct_2(t_game *game)
{
	game->img.hand.hand_img[8].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/187.xpm", &game->img.hand.hand_img[8].x, \
		&game->img.hand.hand_img[8].y);
	game->img.hand.hand_img[8].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[8].img, &game->img.hand.hand_img[8].bits_per_pixel, &game->\
		img.hand.hand_img[8].line_length, &game->img.hand.hand_img[8].endian);
	game->img.hand.hand_img[9].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/188.xpm", &game->img.hand.hand_img[9].x, \
		&game->img.hand.hand_img[9].y);
	game->img.hand.hand_img[9].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[9].img, &game->img.hand.hand_img[9].bits_per_pixel, &game->\
		img.hand.hand_img[9].line_length, &game->img.hand.hand_img[9].endian);
	game->img.hand.hand_img[10].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/189.xpm", &game->img.hand.hand_img[10].x, \
		&game->img.hand.hand_img[10].y);
	game->img.hand.hand_img[10].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[10].img, &game->img.hand.hand_img[10].bits_per_pixel, &game->\
		img.hand.hand_img[10].line_length, &game->img.hand.hand_img[10].endian);
	game->img.hand.hand_img[11].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/190.xpm", &game->img.hand.hand_img[11].x, \
		&game->img.hand.hand_img[11].y);
	game->img.hand.hand_img[11].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[11].img, &game->img.hand.hand_img[11].bits_per_pixel, &game->\
		img.hand.hand_img[11].line_length, &game->img.hand.hand_img[11].endian);
}

void	set_hand_struct_3(t_game *game)
{
	game->img.hand.hand_img[12].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/191.xpm", &game->img.hand.hand_img[12].x, &game->\
		img.hand.hand_img[12].y);
	game->img.hand.hand_img[12].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[12].img, &game->img.hand.hand_img[12].bits_per_pixel, &game->\
		img.hand.hand_img[12].line_length, &game->img.hand.hand_img[12].endian);
	game->img.hand.hand_img[13].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/192.xpm", &game->img.hand.hand_img[13].x, \
		&game->img.hand.hand_img[13].y);
	game->img.hand.hand_img[13].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[13].img, &game->img.hand.hand_img[13].bits_per_pixel, &game->\
		img.hand.hand_img[13].line_length, &game->img.hand.hand_img[13].endian);
	game->img.hand.hand_img[14].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/193.xpm", &game->img.hand.hand_img[14].x, \
		&game->img.hand.hand_img[14].y);
	game->img.hand.hand_img[14].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[14].img, &game->img.hand.hand_img[14].bits_per_pixel, &game->\
		img.hand.hand_img[14].line_length, &game->img.hand.hand_img[14].endian);
	game->img.hand.hand_img[15].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/194.xpm", &game->img.hand.hand_img[15].x, \
		&game->img.hand.hand_img[15].y);
	game->img.hand.hand_img[15].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[15].img, &game->img.hand.hand_img[15].bits_per_pixel, &game->\
		img.hand.hand_img[15].line_length, &game->img.hand.hand_img[15].endian);
}

void	set_hand_struct_4(t_game *game)
{
	game->img.hand.hand_img[16].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/195.xpm", &game->img.hand.hand_img[16].x, \
		&game->img.hand.hand_img[16].y);
	game->img.hand.hand_img[16].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[16].img, &game->img.hand.hand_img[16].bits_per_pixel, &game->\
		img.hand.hand_img[16].line_length, &game->img.hand.hand_img[16].endian);
	game->img.hand.hand_img[17].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/196.xpm", &game->img.hand.hand_img[17].x, \
		&game->img.hand.hand_img[17].y);
	game->img.hand.hand_img[17].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[17].img, &game->img.hand.hand_img[17].bits_per_pixel, &game->\
		img.hand.hand_img[17].line_length, &game->img.hand.hand_img[17].endian);
	game->img.hand.hand_img[18].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/197.xpm", &game->img.hand.hand_img[18].x, \
		&game->img.hand.hand_img[18].y);
	game->img.hand.hand_img[18].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[18].img, &game->img.hand.hand_img[18].bits_per_pixel, &game->\
		img.hand.hand_img[18].line_length, &game->img.hand.hand_img[18].endian);
	game->img.hand.hand_img[19].img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/hand/198.xpm", &game->img.hand.hand_img[19].x, \
		&game->img.hand.hand_img[19].y);
	game->img.hand.hand_img[19].addr = mlx_get_data_addr(game->img.hand.\
		hand_img[19].img, &game->img.hand.hand_img[19].bits_per_pixel, &game->\
		img.hand.hand_img[19].line_length, &game->img.hand.hand_img[19].endian);
}
