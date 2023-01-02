/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute initializer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:22 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/02 15:02:32 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_struct_map(t_game *game, char **av)
{
	game->map.map_path = av[1];
	game->map.gnl_count = 0;
	game->map.north_wall = NULL;
	game->map.south_wall = NULL;
	game->map.east_wall = NULL;
	game->map.west_wall = NULL;
	game->map.floor_char = NULL;
	game->map.ceilling_char = NULL;
	game->map.floor_rgb = 0;
	game->map.ceilling_rgb = 0;
	game->map.map = NULL;
	game->map.started_reading = 0;
	game->map.player_count = 0;
	game->player.fov = D_FOV;
}

void	fill_struct_minimap(t_game *game)
{
	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column \
		* 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * \
		game->settings.minimap_scale;
	game->minimap.pa = (deg_to_rad(game->player.direction));
	game->minimap.step_offset_x = cos(game->minimap.pa) * \
		game->settings.minimap_scale / 10;
	game->minimap.step_offset_y = sin(game->minimap.pa) * \
		game->settings.minimap_scale / 10;
	game->minimap.mapx = game->map.width;
	game->minimap.mapy = game->map.length;
}

void	fill_struct_libx_and_img(t_game *game)
{
	game->libx.mlx = mlx_init();
	game->libx.win = mlx_new_window (game->libx.mlx, \
		SCREEN_WID, SCREEN_LEN, "cub3d");
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, \
		SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, \
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->img.north_img = mlx_xpm_file_to_image(game->libx.mlx, game->map. \
		north_wall, &game->img.north_x, &game->img.north_y);
	game->img.north_addr = mlx_get_data_addr(game->img.north_img, &game->img. \
		north_bits_per_pixel, &game->img.north_line_length, \
		&game->img.north_endian);
	game->img.west_img = mlx_xpm_file_to_image(game->libx.mlx, \
		game->map.west_wall, &game->img.west_x, &game->img.west_y);
	game->img.west_addr = mlx_get_data_addr(game->img.west_img, &game->img. \
		west_bits_per_pixel, &game->img.west_line_length, \
			&game->img.west_endian);
	game->img.south_img = mlx_xpm_file_to_image(game->libx.mlx, game->map \
		.south_wall, &game->img.south_x, &game->img.south_y);
	game->img.south_addr = mlx_get_data_addr(game->img.south_img, &game->img. \
		south_bits_per_pixel, &game->img.south_line_length, \
			&game->img.south_endian);
	game->img.east_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.\
		east_wall, &game->img.east_x, &game->img.east_y);
}

void	fill_struct_img(t_game *game)
{
	game->img.east_addr = mlx_get_data_addr(game->img.east_img, &game->img. \
		east_bits_per_pixel, &game->img.east_line_length, \
			&game->img.east_endian);
	game->img.door_img = mlx_xpm_file_to_image(game->libx.mlx, \
		"images/door.xpm", &game->img.door_x, &game->img.door_y);
	game->img.door_addr = mlx_get_data_addr(game->img.door_img, &game->img. \
		door_bits_per_pixel, &game->img.door_line_length, \
			&game->img.door_endian);
	game->img.wall_y = 0;
	game->img.wall_x = 0;
	game->img.which_wall = 0;
}

void	get_value(t_game *game)
{
	set_scale_factor(game);
	fill_struct_libx_and_img(game);
	fill_struct_img(game);
	game_settings(game);
	fill_struct_minimap(game);
	set_hand_struct(game);
	set_hand_struct_1(game);
	set_hand_struct_2(game);
	set_hand_struct_3(game);
	set_hand_struct_4(game);
	set_hand_struct_5(game);
	set_hand_struct_6(game);
	game->img.hand.left_hand = 0;
	game->img.hand.right_hand = 4;
	game->img.hand.attack = 0;
}
