#include "cub3d.h"

void	append_enemy(t_game *game, int coor_y, int coor_x)
{
	t_enemy *tmp_enemy;

	if (game->enemy == NULL)
	{
		game->enemy = malloc(sizeof(t_enemy));
		game->enemy->posx = 100 * (coor_x + 1) + 50;
		game->enemy->posy = 100 * (coor_y + 1) + 50;
		game->enemy->alive = 1;
		game->enemy->next = NULL;
		game->enemy->head = game->enemy;
	}
	else
	{
		printf("lala\n");
		tmp_enemy = game->enemy;
		while (tmp_enemy->next != NULL)
		{
			tmp_enemy = tmp_enemy->next;
		}
		tmp_enemy->next = malloc(sizeof(t_enemy));
		tmp_enemy->next->posx = 100 * (coor_x + 1) + 50;
		tmp_enemy->next->posy = 100 * (coor_y + 1) + 50;
		tmp_enemy->next->alive = 1;
		tmp_enemy->next->head = game->enemy;
		tmp_enemy->next->next = NULL;
		printf("deneme\n");
	}
}

int	is_line_valid(t_game *game, char *line, int coor_y)
{
	int	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 32 && line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'W' && line[i] != 'E' && line[i] != '\n' \
			&& line[i] != '1' && line[i] != '0' && line[i] != 'V')
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
			game->player.pos_x = 100 * (i + 1) + 50;
			game->player.pos_y = 100 * (coor_y + 1) + 50;
			game->map.player_count += 1;
		}
		else if (line[i] == 'V')
		{
			append_enemy(game, coor_y, i);
		}
		++i;
	}
	return (1);
}

int	check_component(t_game *game)
{
	int	i;

	game->enemy = NULL;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (!is_line_valid(game, game->map.map[i], i))
			return (1);
		++i;
	}
	if (game->map.player_count != 1)
		return (2);
	return (0);
}