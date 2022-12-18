#include "cub3d.h"

void	append_enemy(t_game *game)
{
	t_enemy *tmp_enemy;

	if (game->enemy == NULL)
	{
		game->enemy = malloc(sizeof(t_enemy));
		game->enemy->alive = 0;
		game->enemy->next = NULL;
		game->enemy->head = game->enemy;
		game->enemy_count = 1;
		game->enemy->attack_state = -1;
		game->enemy->frame_counter = 0;
		game->enemy->sleep = 0;
	}
	else
	{
		tmp_enemy = game->enemy;
		while (tmp_enemy->next != NULL)
		{
			tmp_enemy = tmp_enemy->next;
		}
		tmp_enemy->next = malloc(sizeof(t_enemy));
		tmp_enemy->next->alive = 0;
		tmp_enemy->next->head = game->enemy;
		tmp_enemy->next->next = NULL;
		++game->enemy_count;
		tmp_enemy->next->attack_state = -1;
		tmp_enemy->next->frame_counter = 0;
		tmp_enemy->next->sleep = 0;
	}
}

void	append_spawn(t_game *game, int pos_y, int pos_x)
{
	t_spawn *tmp_spawn;

	if (game->spawn == NULL)
	{
		game->spawn = malloc(sizeof(t_spawn));
		game->spawn->pos_x = 100 * (pos_x + 1) + 50;
		game->spawn->pos_y = 100 * (pos_y + 1) + 50;
		game->spawn->next = NULL;
		game->spawn_count = 1;
	}
	else
	{
		tmp_spawn = game->spawn;
		while (tmp_spawn->next != NULL)
		{
			tmp_spawn = tmp_spawn->next;
		}
		tmp_spawn->next = malloc(sizeof(t_spawn));
		tmp_spawn->next->pos_x = 100 * (pos_x + 1) + 50;
		tmp_spawn->next->pos_y = 100 * (pos_y + 1) + 50;
		tmp_spawn->next->next = NULL;
		++game->spawn_count;
	}
}

int	is_line_valid(t_game *game, char *line, int coor_y)
{
	int	i;
	(void)coor_y;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 32 && line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'W' && line[i] != 'E' && line[i] != '\n' \
			&& line[i] != '1' && line[i] != '0' && line[i] != 'V' \
			&& line[i] != 'C')
			return (0);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			if (line[i] == 'N')
				game->player.direction = 90;
			if (line[i] == 'S')
				game->player.direction = 270;
			if (line[i] == 'W')
				game->player.direction = 180;
			if (line[i] == 'E')
				game->player.direction = 0;//BAKALIM
			game->map.player_count += 1;
		}
		else if (line[i] == 'V')
		{
			append_spawn(game, coor_y, i);
		}
		++i;
	}
	return (1);
}

int	check_component(t_game *game)
{
	int	i;

	game->enemy = NULL;
	game->spawn = NULL;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (!is_line_valid(game, game->map.map[i], i))
			return (1);
		++i;
	}
	if (game->map.player_count != 1)
		return (2);
	for (int n = 0;n < 5;++n)
	{
		append_enemy(game);
	}
	return (0);
}