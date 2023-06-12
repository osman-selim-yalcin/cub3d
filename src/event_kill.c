#include "cub3d.h"

void	kill_all(t_game *game)
{
	t_enemy *current_enemy;

	current_enemy = game->enemy;
	while (current_enemy != NULL)
	{
		current_enemy->alive = 0;
		current_enemy = current_enemy->next;
	}
}

void	revive_all(t_game *game)
{
	t_enemy *current_enemy;

	current_enemy = game->enemy;
	while (current_enemy != NULL)
	{
		current_enemy->alive = 1;
		current_enemy = current_enemy->next;
	}
}