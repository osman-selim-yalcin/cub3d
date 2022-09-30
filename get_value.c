#include "cub3d.h"

void fill_map(t_game *game, char **av)
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
}

void get_value(t_game *game, char **av)
{
	fill_map(game, av);
}