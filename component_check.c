#include "cub3d.h"

int	is_line_valid(t_game *game, char *line)
{
	int	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 32 && line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'W' && line[i] != 'E' && line[i] != '\n' \
			&& line[i] != '1' && line[i] != '0')
			return (0);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			if (line[i] == 'N')
				game->player.direction = M_PI / 2;
			if (line[i] == 'S')
				game->player.direction = 3 * M_PI / 2;
			if (line[i] == 'W')
				game->player.direction = M_PI;
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
		if (!is_line_valid(game, game->map.map[i]))
			return (1);
		++i;
	}
	if (game->map.player_count != 1)
		return (2);
	return (0);
}