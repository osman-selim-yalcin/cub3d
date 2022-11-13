#include "cub3d.h"

int	check_door_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'C')
			{
				if (game->map.map[i][j + 1] != '1' && game->map.map[i][j - 1] != '1')
				{
					if (game->map.map[i - 1][j] != '1' || game->map.map[i + 1][j] != '1')
						return (1);
				}
				else if (game->map.map[i + 1][j] != '1' && game->map.map[i - 1][j] != '1')
				{
					if (game->map.map[i][j + 1] != '1' || game->map.map[i][j - 1] != '1')
						return (1);
				}
				else
					return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}