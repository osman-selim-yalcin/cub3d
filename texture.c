#include "cub3d.h"

unsigned int take_texture(t_game *game, int x, int y, int which_wall)
{
	char *dst;
	if (which_wall == 1)//north
	{
		game->img.west_wall_index = 0;
		game->img.south_wall_index = 0;	
		game->img.east_wall_index = 0;	
		dst = game->img.north_addr + (y * game->img.north_line_length + x * (game->img.north_bits_per_pixel / 8));	
	}
	else if (which_wall == 2)//west
	{
		game->img.north_wall_index = 0;	
		game->img.south_wall_index = 0;	
		game->img.east_wall_index = 0;	
		dst = game->img.west_addr + (y * game->img.west_line_length + x * (game->img.west_bits_per_pixel / 8));
	}
	else if (which_wall == 3) //south
	{
		game->img.north_wall_index = 0;	
		game->img.west_wall_index = 0;
		game->img.east_wall_index = 0;	
		dst = game->img.south_addr + (y * game->img.south_line_length + x * (game->img.south_bits_per_pixel / 8));
	}
	else //east
	{
		game->img.west_wall_index = 0;
		game->img.north_wall_index = 0;
		game->img.south_wall_index = 0;	
		dst = game->img.east_addr + (y * game->img.east_line_length + x * (game->img.east_bits_per_pixel / 8));
	}
	return (*(unsigned int*)dst);
}