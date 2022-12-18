#include "cub3d.h"

unsigned int take_texture(t_game *game, int x, int y, int which_wall)
{
	char *dst = NULL;
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
	else if (which_wall == 4)//east
	{
		dst = game->img.east_addr + (y * game->img.east_line_length + x * (game->img.east_bits_per_pixel / 8));
	}
	else if (which_wall == 5) //enemy
	{
		if (game->enemy->attack_state == -1 && game->enemy->vanish_state == -1)
			dst = game->img.enemy_idle_addr[game->enemy_idle_state] + (y * game->img.enemy_line_length[0] + x * (game->img.enemy_bits_per_pixel[0] / 8));
		else if (game->enemy->vanish_state != -1)
			dst = game->img.enemy_vanish_addr[game->enemy->vanish_state] + (y * game->img.enemy_line_length[1] + x * (game->img.enemy_bits_per_pixel[1] / 8));
		else
		{
			dst = game->img.enemy_attack_addr[game->enemy->attack_state] + (y * game->img.enemy_line_length[0] + x * (game->img.enemy_bits_per_pixel[0] / 8));
		}	
	}
	else if (which_wall == 6) // ceil
	{
		dst = game->img.ceil_addr + (y * game->img.ceil_line_length + x * (game->img.ceil_bits_per_pixel / 8));	
	}
	else if (which_wall == 7) // door
	{
		dst = game->img.door_addr + (y * game->img.door_line_length + x * (game->img.door_bits_per_pixel / 8));	
	}
	else if (which_wall == 10)//left
	{
		dst = game->img.hand.hand_img[game->img.hand.left_hand].addr + (y * game->img.hand.hand_img[game->img.hand.left_hand].line_length + x * (game->img.hand.hand_img[game->img.hand.left_hand].bits_per_pixel / 8));
	}
	else if (which_wall == 11)//right
	{
		dst = game->img.hand.hand_img[game->img.hand.right_hand].addr + (y * game->img.hand.hand_img[game->img.hand.right_hand].line_length + x * (game->img.hand.hand_img[game->img.hand.right_hand].bits_per_pixel / 8));
	}
	else
	{
		// dst = game->img.enemy_idle_addr[game->enemy_idle_state] + (y * game->img.enemy_line_length + x * (game->img.enemy_bits_per_pixel / 8));
	}
	return (*(unsigned int*)dst);
}