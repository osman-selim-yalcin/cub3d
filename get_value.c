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
	game->minimap.px = game->player.pos_x / 100 * 20;
	game->minimap.py = game->player.pos_y / 100 * 20;
	game->minimap.pa = fabs(deg_to_rad(game->player.direction));
	game->minimap.pa -= M_PI;
	if (game->minimap.pa < 0)
	{
		game->minimap.pa += 2 * M_PI;
	}
	if (game->minimap.pa > 2 * M_PI)
	{
		game->minimap.pa -= 2 * M_PI;
	}
	game->minimap.pdx = cos(game->minimap.pa) * 2;
	game->minimap.pdy = sin(game->minimap.pa) * 2;
	game->minimap.mapx = game->map.width;
	game->minimap.mapy = game->map.length;
	game->minimap.mapsize = game->map.width * game->map.length;
	game->minimap.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->minimap.addr = mlx_get_data_addr(game->img.img, &game->minimap.bits_per_pixel, &game->minimap.line_length, &game->minimap.endian);
}

void fill_struct_libx_and_img(t_game *game)
{
	int x;
	int y;

	game->libx.mlx = mlx_init();
	game->libx.win = mlx_new_window(game->libx.mlx, SCREEN_WID, SCREEN_LEN, "cub3d");

	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);

	game->img.north_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.north_wall, &x, &y);
	game->img.north_addr = mlx_get_data_addr(game->img.north_img, &game->img.north_bits_per_pixel, &game->img.north_line_length, &game->img.north_endian);

	game->img.west_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.west_wall, &x, &y);
	game->img.west_addr = mlx_get_data_addr(game->img.west_img, &game->img.west_bits_per_pixel, &game->img.west_line_length, &game->img.west_endian);

	game->img.south_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.south_wall, &x, &y);
	game->img.south_addr = mlx_get_data_addr(game->img.south_img, &game->img.south_bits_per_pixel, &game->img.south_line_length, &game->img.south_endian);

	game->img.east_img = mlx_xpm_file_to_image(game->libx.mlx, game->map.east_wall, &x, &y);
	game->img.east_addr = mlx_get_data_addr(game->img.east_img, &game->img.east_bits_per_pixel, &game->img.east_line_length, &game->img.east_endian);

}

void get_value(t_game *game)
{
	fill_struct_libx_and_img(game);
	fill_struct_minimap(game);
}

