#include "cub3d.h"

void fill_struct_map(t_game *game, char **av)
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
	game->enemy_idle_state = 0;
}

void fill_struct_minimap(t_game *game)
{
	game->minimap.pos_x = (game->player.pos_x - game->minimap.empty_column * 100) / 100 * game->settings.minimap_scale;
	game->minimap.pos_y = game->player.pos_y / 100 * game->settings.minimap_scale;
	game->minimap.pa = (deg_to_rad(game->player.direction));


	game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
	game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	
	
	game->minimap.mapx = game->map.width;
	game->minimap.mapy = game->map.length;
}

void fill_struct_libx_and_img(t_game *game)
{
	game->libx.mlx = mlx_init();
	game->libx.win = mlx_new_window(game->libx.mlx, SCREEN_WID, SCREEN_LEN, "cub3d");

	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);

	game->img.north_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.north_wall, &game->img.north_x, &game->img.north_y);
	game->img.north_addr = mlx_get_data_addr(game->img.north_img, &game->img.north_bits_per_pixel, &game->img.north_line_length, &game->img.north_endian);

	game->img.west_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.west_wall,  &game->img.west_x, &game->img.west_y);
	game->img.west_addr = mlx_get_data_addr(game->img.west_img, &game->img.west_bits_per_pixel, &game->img.west_line_length, &game->img.west_endian);

	game->img.south_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.south_wall, &game->img.south_x, &game->img.south_y);
	game->img.south_addr = mlx_get_data_addr(game->img.south_img, &game->img.south_bits_per_pixel, &game->img.south_line_length, &game->img.south_endian);

	game->img.east_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.east_wall, &game->img.east_x, &game->img.east_y);
	game->img.east_addr = mlx_get_data_addr(game->img.east_img, &game->img.east_bits_per_pixel, &game->img.east_line_length, &game->img.east_endian);

	game->img.enemy_idle_img[0] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/idle/idle1.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_idle_addr[0] = mlx_get_data_addr(game->img.enemy_idle_img[0], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_idle_img[1] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/idle/idle2.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_idle_addr[1] = mlx_get_data_addr(game->img.enemy_idle_img[1], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_idle_img[2] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/idle/idle3.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_idle_addr[2] = mlx_get_data_addr(game->img.enemy_idle_img[2], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_idle_img[3] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/idle/idle4.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_idle_addr[3] = mlx_get_data_addr(game->img.enemy_idle_img[3], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_idle_img[4] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/idle/idle5.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_idle_addr[4] = mlx_get_data_addr(game->img.enemy_idle_img[4], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_idle_img[5] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/idle/idle6.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_idle_addr[5] = mlx_get_data_addr(game->img.enemy_idle_img[5], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_idle_img[6] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/idle/idle7.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_idle_addr[6] = mlx_get_data_addr(game->img.enemy_idle_img[6], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	
	
	game->img.enemy_attack_img[0] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/shriek/shriek1.xpm", &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_attack_addr[0] = mlx_get_data_addr(game->img.enemy_attack_img[0], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_attack_img[1] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/shriek/shriek2.xpm", &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_attack_addr[1] = mlx_get_data_addr(game->img.enemy_attack_img[1], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_attack_img[2] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/shriek/shriek3.xpm", &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_attack_addr[2] = mlx_get_data_addr(game->img.enemy_attack_img[2], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);
	game->img.enemy_attack_img[3] = mlx_xpm_file_to_image(game->libx.mlx, "images/ghost/shriek/shriek4.xpm", &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_attack_addr[3] = mlx_get_data_addr(game->img.enemy_attack_img[3], &game->img.enemy_bits_per_pixel[0], &game->img.enemy_line_length[0], &game->img.enemy_endian[0]);


	game->img.ceil_img = mlx_xpm_file_to_image(game->libx.mlx, "images/0.xpm", &game->img.ceilx, &game->img.ceily);
	game->img.ceil_addr = mlx_get_data_addr(game->img.ceil_img, &game->img.ceil_bits_per_pixel, &game->img.ceil_line_length, &game->img.ceil_endian);

	game->img.door_img = mlx_xpm_file_to_image(game->libx.mlx, "images/door.xpm", &game->img.door_x, &game->img.door_y);
	game->img.door_addr = mlx_get_data_addr(game->img.door_img, &game->img.door_bits_per_pixel, &game->img.door_line_length, &game->img.door_endian);

	game->img.wall_y = 0;
	game->img.wall_x = 0;
	game->img.ceil_index_x = 0;
	game->img.ceil_index_y = 0;
	game->img.which_wall = 0;
}

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

void	find_first_empty_columns(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (1)
	{
		i = 0;
		while (i < game->map.length + 2 && game->map.map[i][j] == '2')
			++i;
		if (i < game->map.length + 2)
		{
			game->minimap.empty_column = j - 1;
			return ;
		}
		++j;
	}
}

void	find_last_empty_columns(t_game *game)
{
	int	i;
	int	j;

	game->minimap.empty_column2 = 1;
	j = game->map.total_column - 1;
	while (1)
	{
		i = 0;
		while (i < game->map.total_row && game->map.map[i][j - game->minimap.empty_column2] == '2')
			++i;
		if (i < game->map.total_row)
			return ;
		++game->minimap.empty_column2;
	}
}

void	set_scale_factor(t_game *game)
{
	if ((float)(game->map.total_column - game->minimap.empty_column - game->minimap.empty_column2) / game->map.length < (float)SCREEN_WID / SCREEN_LEN)//len-vertical wider
	{
		game->minimap.full_scale = ((float)SCREEN_LEN / (game->map.length + 1)) - 1;
	}
	else
	{
		game->minimap.full_scale = (float)SCREEN_WID / (game->map.total_column - game->minimap.empty_column - game->minimap.empty_column2 + 1);
	}
	game->minimap.shift_x = 0;
	game->minimap.shift_y = 0;
}


void	set_hand_struct(t_game *game)
{
	game->img.hand.hand_img[0].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/179.xpm", &game->img.hand.hand_img[0].x, &game->img.hand.hand_img[0].y);
	game->img.hand.hand_img[0].addr = mlx_get_data_addr(game->img.hand.hand_img[0].img, &game->img.hand.hand_img[0].bits_per_pixel, &game->img.hand.hand_img[0].line_length, &game->img.hand.hand_img[0].endian);
	game->img.hand.hand_img[1].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/180.xpm", &game->img.hand.hand_img[1].x, &game->img.hand.hand_img[1].y);
	game->img.hand.hand_img[1].addr = mlx_get_data_addr(game->img.hand.hand_img[1].img, &game->img.hand.hand_img[1].bits_per_pixel, &game->img.hand.hand_img[1].line_length, &game->img.hand.hand_img[1].endian);
	game->img.hand.hand_img[2].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/181.xpm", &game->img.hand.hand_img[2].x, &game->img.hand.hand_img[2].y);
	game->img.hand.hand_img[2].addr = mlx_get_data_addr(game->img.hand.hand_img[2].img, &game->img.hand.hand_img[2].bits_per_pixel, &game->img.hand.hand_img[2].line_length, &game->img.hand.hand_img[2].endian);
	game->img.hand.hand_img[3].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/182.xpm", &game->img.hand.hand_img[3].x, &game->img.hand.hand_img[3].y);
	game->img.hand.hand_img[3].addr = mlx_get_data_addr(game->img.hand.hand_img[3].img, &game->img.hand.hand_img[3].bits_per_pixel, &game->img.hand.hand_img[3].line_length, &game->img.hand.hand_img[3].endian);
	game->img.hand.hand_img[4].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/183.xpm", &game->img.hand.hand_img[4].x, &game->img.hand.hand_img[4].y);
	game->img.hand.hand_img[4].addr = mlx_get_data_addr(game->img.hand.hand_img[4].img, &game->img.hand.hand_img[4].bits_per_pixel, &game->img.hand.hand_img[4].line_length, &game->img.hand.hand_img[4].endian);
	game->img.hand.hand_img[5].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/184.xpm", &game->img.hand.hand_img[5].x, &game->img.hand.hand_img[5].y);
	game->img.hand.hand_img[5].addr = mlx_get_data_addr(game->img.hand.hand_img[5].img, &game->img.hand.hand_img[5].bits_per_pixel, &game->img.hand.hand_img[5].line_length, &game->img.hand.hand_img[5].endian);
	game->img.hand.hand_img[6].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/185.xpm", &game->img.hand.hand_img[6].x, &game->img.hand.hand_img[6].y);
	game->img.hand.hand_img[6].addr = mlx_get_data_addr(game->img.hand.hand_img[6].img, &game->img.hand.hand_img[6].bits_per_pixel, &game->img.hand.hand_img[6].line_length, &game->img.hand.hand_img[6].endian);
	game->img.hand.hand_img[7].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/186.xpm", &game->img.hand.hand_img[7].x, &game->img.hand.hand_img[7].y);
	game->img.hand.hand_img[7].addr = mlx_get_data_addr(game->img.hand.hand_img[7].img, &game->img.hand.hand_img[7].bits_per_pixel, &game->img.hand.hand_img[7].line_length, &game->img.hand.hand_img[7].endian);
	game->img.hand.hand_img[8].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/187.xpm", &game->img.hand.hand_img[8].x, &game->img.hand.hand_img[8].y);
	game->img.hand.hand_img[8].addr = mlx_get_data_addr(game->img.hand.hand_img[8].img, &game->img.hand.hand_img[8].bits_per_pixel, &game->img.hand.hand_img[8].line_length, &game->img.hand.hand_img[8].endian);
	game->img.hand.hand_img[9].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/188.xpm", &game->img.hand.hand_img[9].x, &game->img.hand.hand_img[9].y);
	game->img.hand.hand_img[9].addr = mlx_get_data_addr(game->img.hand.hand_img[9].img, &game->img.hand.hand_img[9].bits_per_pixel, &game->img.hand.hand_img[9].line_length, &game->img.hand.hand_img[9].endian);
	game->img.hand.hand_img[10].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/189.xpm", &game->img.hand.hand_img[10].x, &game->img.hand.hand_img[10].y);
	game->img.hand.hand_img[10].addr = mlx_get_data_addr(game->img.hand.hand_img[10].img, &game->img.hand.hand_img[10].bits_per_pixel, &game->img.hand.hand_img[10].line_length, &game->img.hand.hand_img[10].endian);
	game->img.hand.hand_img[11].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/190.xpm", &game->img.hand.hand_img[11].x, &game->img.hand.hand_img[11].y);
	game->img.hand.hand_img[11].addr = mlx_get_data_addr(game->img.hand.hand_img[11].img, &game->img.hand.hand_img[11].bits_per_pixel, &game->img.hand.hand_img[11].line_length, &game->img.hand.hand_img[11].endian);
	game->img.hand.hand_img[12].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/191.xpm", &game->img.hand.hand_img[12].x, &game->img.hand.hand_img[12].y);
	game->img.hand.hand_img[12].addr = mlx_get_data_addr(game->img.hand.hand_img[12].img, &game->img.hand.hand_img[12].bits_per_pixel, &game->img.hand.hand_img[12].line_length, &game->img.hand.hand_img[12].endian);
}

void	set_hand_struct_v2(t_game *game)
{
	game->img.hand.hand_img[13].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/192.xpm", &game->img.hand.hand_img[13].x, &game->img.hand.hand_img[13].y);
	game->img.hand.hand_img[13].addr = mlx_get_data_addr(game->img.hand.hand_img[13].img, &game->img.hand.hand_img[13].bits_per_pixel, &game->img.hand.hand_img[13].line_length, &game->img.hand.hand_img[13].endian);
	game->img.hand.hand_img[14].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/193.xpm", &game->img.hand.hand_img[14].x, &game->img.hand.hand_img[14].y);
	game->img.hand.hand_img[14].addr = mlx_get_data_addr(game->img.hand.hand_img[14].img, &game->img.hand.hand_img[14].bits_per_pixel, &game->img.hand.hand_img[14].line_length, &game->img.hand.hand_img[14].endian);
	game->img.hand.hand_img[15].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/194.xpm", &game->img.hand.hand_img[15].x, &game->img.hand.hand_img[15].y);
	game->img.hand.hand_img[15].addr = mlx_get_data_addr(game->img.hand.hand_img[15].img, &game->img.hand.hand_img[15].bits_per_pixel, &game->img.hand.hand_img[15].line_length, &game->img.hand.hand_img[15].endian);
	game->img.hand.hand_img[16].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/195.xpm", &game->img.hand.hand_img[16].x, &game->img.hand.hand_img[16].y);
	game->img.hand.hand_img[16].addr = mlx_get_data_addr(game->img.hand.hand_img[16].img, &game->img.hand.hand_img[16].bits_per_pixel, &game->img.hand.hand_img[16].line_length, &game->img.hand.hand_img[16].endian);
	game->img.hand.hand_img[17].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/196.xpm", &game->img.hand.hand_img[17].x, &game->img.hand.hand_img[17].y);
	game->img.hand.hand_img[17].addr = mlx_get_data_addr(game->img.hand.hand_img[17].img, &game->img.hand.hand_img[17].bits_per_pixel, &game->img.hand.hand_img[17].line_length, &game->img.hand.hand_img[17].endian);
	game->img.hand.hand_img[18].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/197.xpm", &game->img.hand.hand_img[18].x, &game->img.hand.hand_img[18].y);
	game->img.hand.hand_img[18].addr = mlx_get_data_addr(game->img.hand.hand_img[18].img, &game->img.hand.hand_img[18].bits_per_pixel, &game->img.hand.hand_img[18].line_length, &game->img.hand.hand_img[18].endian);
	game->img.hand.hand_img[19].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/198.xpm", &game->img.hand.hand_img[19].x, &game->img.hand.hand_img[19].y);
	game->img.hand.hand_img[19].addr = mlx_get_data_addr(game->img.hand.hand_img[19].img, &game->img.hand.hand_img[19].bits_per_pixel, &game->img.hand.hand_img[19].line_length, &game->img.hand.hand_img[19].endian);
	game->img.hand.hand_img[20].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/199.xpm", &game->img.hand.hand_img[20].x, &game->img.hand.hand_img[20].y);
	game->img.hand.hand_img[20].addr = mlx_get_data_addr(game->img.hand.hand_img[20].img, &game->img.hand.hand_img[20].bits_per_pixel, &game->img.hand.hand_img[20].line_length, &game->img.hand.hand_img[20].endian);
	game->img.hand.hand_img[21].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/200.xpm", &game->img.hand.hand_img[21].x, &game->img.hand.hand_img[21].y);
	game->img.hand.hand_img[21].addr = mlx_get_data_addr(game->img.hand.hand_img[21].img, &game->img.hand.hand_img[21].bits_per_pixel, &game->img.hand.hand_img[21].line_length, &game->img.hand.hand_img[21].endian);
	game->img.hand.hand_img[22].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/201.xpm", &game->img.hand.hand_img[22].x, &game->img.hand.hand_img[22].y);
	game->img.hand.hand_img[22].addr = mlx_get_data_addr(game->img.hand.hand_img[22].img, &game->img.hand.hand_img[22].bits_per_pixel, &game->img.hand.hand_img[22].line_length, &game->img.hand.hand_img[22].endian);
	game->img.hand.hand_img[23].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/202.xpm", &game->img.hand.hand_img[23].x, &game->img.hand.hand_img[23].y);
	game->img.hand.hand_img[23].addr = mlx_get_data_addr(game->img.hand.hand_img[23].img, &game->img.hand.hand_img[23].bits_per_pixel, &game->img.hand.hand_img[23].line_length, &game->img.hand.hand_img[23].endian);
	game->img.hand.hand_img[24].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/203.xpm", &game->img.hand.hand_img[24].x, &game->img.hand.hand_img[24].y);
	game->img.hand.hand_img[24].addr = mlx_get_data_addr(game->img.hand.hand_img[24].img, &game->img.hand.hand_img[24].bits_per_pixel, &game->img.hand.hand_img[24].line_length, &game->img.hand.hand_img[24].endian);
	game->img.hand.hand_img[25].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/204.xpm", &game->img.hand.hand_img[25].x, &game->img.hand.hand_img[25].y);
	game->img.hand.hand_img[25].addr = mlx_get_data_addr(game->img.hand.hand_img[25].img, &game->img.hand.hand_img[25].bits_per_pixel, &game->img.hand.hand_img[25].line_length, &game->img.hand.hand_img[25].endian);
	game->img.hand.hand_img[26].img = mlx_xpm_file_to_image(game->libx.mlx, "images/hand/205.xpm", &game->img.hand.hand_img[26].x, &game->img.hand.hand_img[26].y);
	game->img.hand.hand_img[26].addr = mlx_get_data_addr(game->img.hand.hand_img[26].img, &game->img.hand.hand_img[26].bits_per_pixel, &game->img.hand.hand_img[26].line_length, &game->img.hand.hand_img[26].endian);

}

void	get_value(t_game *game)
{
	find_first_empty_columns(game);
	find_last_empty_columns(game);
	set_scale_factor(game);
	fill_struct_libx_and_img(game);
	game_settings(game);
	fill_struct_minimap(game);
	set_hand_struct(game);
	set_hand_struct_v2(game);
	game->img.hand.left_hand = 0;
	game->img.hand.right_hand = 4;
	game->img.hand.attack = 0;
}
