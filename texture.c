#include "cub3d.h"

unsigned int take_texture(t_game *game, int x, int y, int which_wall)
{
	char *dst;
	if (which_wall == 1)//north
	{
		dst = game->img.north_addr + (y * game->img.north_line_length + x * (game->img.north_bits_per_pixel / 8));	
	}
	else if (which_wall == 2)//west
	{
		dst = game->img.west_addr + (y * game->img.west_line_length + x * (game->img.west_bits_per_pixel / 8));
	}
	else if (which_wall == 3) //south
	{
		dst = game->img.south_addr + (y * game->img.south_line_length + x * (game->img.south_bits_per_pixel / 8));
	}
	else //east
	{
		dst = game->img.east_addr + (y * game->img.east_line_length + x * (game->img.east_bits_per_pixel / 8));
	}
	return (*(unsigned int*)dst);
}