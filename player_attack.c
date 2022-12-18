#include "cub3d.h"


void p_attack(t_game *game)
{
	t_enemy *tmp_enemy;
	int which_enemy;
	
	tmp_enemy = game->enemy;
	which_enemy = game->enemy_count;
	while (tmp_enemy && which_enemy > 0)
	{
		while (game->enemy->id != which_enemy && game->enemy->next)
			game->enemy = game->enemy->next;
		if (game->enemy->alive)
		{		
			if (game->enemy->distance < 600 && SCREEN_WID / 2 + 10 > game->enemy->pixel - (game->enemy->width / 4) && SCREEN_WID / 2 - 50 < game->enemy->pixel + (game->enemy->width / 4))
			{
				game->enemy->vanish_state = 0;
				break;
			}
		}
		which_enemy--;
		game->enemy = tmp_enemy;
	}
	game->enemy = tmp_enemy;
}