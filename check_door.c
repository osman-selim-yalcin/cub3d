#include "cub3d.h"

int	check_door_position(t_game *game)
{
	get_door_position(game);
	return (0);
}

void	get_door_position(t_game *game)
{
	int i;
	int j;
	int	counter;

	game->map.doors = malloc(sizeof(int *) * (game->map.door_number + 1));
	counter = 0;
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'C')
			{
				game->map.doors[counter] = malloc(sizeof(int) * 2);
				game->map.doors[counter][1] = 100 * (i) + 50;
				game->map.doors[counter][0] = 100 * (j) + 50;
				++counter;
			}
			else if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S' || game->map.map[i][j] == 'W' || game->map.map[i][j] == 'E')
			{
				game->player.pos_x = 100 * (j) + 50;
				game->player.pos_y = 100 * (i) + 50;
			}
			++j;
		}
		++i;
	}
	game->map.doors[counter] = NULL;
}
