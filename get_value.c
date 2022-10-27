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

	game->img.enemy_img = mlx_xpm_file_to_image(game->libx.mlx, "images/adam.xpm",  &game->img.enemy_x, &game->img.enemy_y);
	game->img.enemy_addr = mlx_get_data_addr(game->img.enemy_img, &game->img.enemy_bits_per_pixel, &game->img.enemy_line_length, &game->img.enemy_endian);

	game->img.wall_y = 0;
	game->img.wall_x = 0;
	game->img.which_wall = 0;
}

void	game_settings(t_game *game)
{
	game->settings.minimap_scale = 20;
	game->settings.step_size = game->settings.minimap_scale / 10;
	game->settings.player_size = game->settings.minimap_scale / 4;
	game->settings.ray_len = 2 * game->settings.minimap_scale / 5;
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

void fill_struct_enemy(t_game *game)
{
	game->enemy.posx = game->player.pos_x - 110;
	game->enemy.posy = game->player.pos_y - 100;
}


void	get_value(t_game *game)
{
	fill_struct_libx_and_img(game);
	game_settings(game);
	find_first_empty_columns(game);
	fill_struct_minimap(game);
	fill_struct_enemy(game);
}

