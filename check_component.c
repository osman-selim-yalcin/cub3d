#include "cub3d.h"


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
			&& line[i] != '1' && line[i] != '0' && line[i] != 'C')
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
		++i;
	}
	return (1);
}

int	check_component(t_game *game)
{
	int	i;

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